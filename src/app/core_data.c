#include "app/core_data.h"
#include "app/file_io.h"
#include "app/generator.h"

#include "stb/stb_ds.h"

#include <ctype.h>

core_data_t core_data = CORE_DATA_INIT();

core_data_t* core_data_get()
{
  return &core_data;
}

void core_data_init()
{
  core_data_read_file("../files/perspectives.txt", core_data.perspectives_txt, &core_data.perspectives, &core_data.perspectives_len);
  core_data_read_file("../files/genres.txt",       core_data.genres_txt,       &core_data.genres,       &core_data.genres_len);
  core_data_read_file("../files/verbs.txt",        core_data.verbs_txt,        &core_data.verbs,        &core_data.verbs_len);
  core_data_read_file("../files/nouns.txt",        core_data.nouns_txt,        &core_data.nouns,        &core_data.nouns_len);
  core_data_read_file("../files/adjectives.txt",   core_data.adjectives_txt,   &core_data.adjectives,   &core_data.adjectives_len);
  core_data_read_file("../files/settings.txt",     core_data.settings_txt,     &core_data.settings,     &core_data.settings_len);
  core_data_read_file("../files/themes.txt",       core_data.themes_txt,       &core_data.themes,       &core_data.themes_len);

  core_data_check_duplicates(core_data.perspectives, core_data.perspectives_len);
  core_data_check_duplicates(core_data.genres,       core_data.genres_len);
  core_data_check_duplicates(core_data.verbs,        core_data.verbs_len);
  core_data_check_duplicates(core_data.nouns,        core_data.nouns_len);
  core_data_check_duplicates(core_data.adjectives,   core_data.adjectives_len);
  core_data_check_duplicates(core_data.settings,     core_data.settings_len);
  core_data_check_duplicates(core_data.themes,       core_data.themes_len);

  
  // pre-generate shared words
  core_data.goal_adj         = generator_get_adjective();
  core_data.goal_noun        = generator_get_noun();
  core_data.antagonist_adj   = generator_get_adjective();
  core_data.antagonist_noun  = generator_get_noun();
  core_data.protagonist_adj  = generator_get_adjective();
  core_data.protagonist_noun = generator_get_noun();
}
void core_data_cleanup()
{  
  arrfree(core_data.perspectives);
  free(core_data.perspectives_txt);
  arrfree(core_data.genres);
  free(core_data.genres_txt);
  arrfree(core_data.verbs);
  free(core_data.verbs_txt);
  arrfree(core_data.nouns);
  free(core_data.nouns_txt);
  arrfree(core_data.adjectives);
  free(core_data.adjectives_txt);
  arrfree(core_data.settings);
  free(core_data.settings_txt);
  arrfree(core_data.themes);
  free(core_data.themes_txt);
}

void core_data_read_file(const char* file_path, char* txt, char*** arr, int* len)
{
  if (!file_io_check_exists(file_path))
  { ERR("file: %s, doesnt exist.\n", file_path); }
 
  int txt_len = 0;
  txt = file_io_read_len(file_path, &txt_len);

  for (int i = 0; i < txt_len; ++i)
  {
    if (( i <= 0 && isalpha(txt[i]) )           ||
        ( (txt[i-1] == '\0' || isspace(txt[i-1])) && isalpha(txt[i]) ) )
      {
        // char* start = &txt[i]; // @TMP:
        arrput(*arr, &txt[i]);
        (*len)++;
        i++;
  
        // add \0 to end of string
        while (i < txt_len && !isspace(txt[i]))
        { i++; }
        txt[i] = '\0';

        // P_STR(start);
      }
  }

  // @TMP: print all strings
  // for (int i = 0; i < (*len); ++i)
  // {
  //   P_STR(arr[i]);
  // }

  // have to free after, bc themes[x] is pointer into txt
  // free(txt);
  // core_data.themes_txt = txt;

}

void core_data_check_duplicates_named(char** arr, int len, const char* name)
{
  for (int x = 0; x < len; ++x)
  {
    for (int y = 0; y < len; ++y)
    {
      if (x == y) { continue; }
      if (strcmp(arr[x], arr[y]) == 0) // matches
      {
        P_ERR("duplicate %s and %s in %s\n", arr[x], arr[y], name);
      }
    }
  }
}
