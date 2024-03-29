#include "app/generator.h"
#include "math/math_inc.h"

void generator_print_gameplay()
{
  core_data_t* core_data = core_data_get();
  
  int idx = 0;
  int old_idx = 0;  // used when checking duplicates
  
  // -- perspective
  idx = rand_int_range(0, core_data->perspectives_len);
  const char* perspective = core_data->perspectives[idx];
  
  // -- core_data->genres
  idx = rand_int_range(0, core_data->genres_len);
  const char* genre_01 =  core_data->genres[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->genres_len); }
  const char* genre_02 = core_data->genres[idx];
  
  // -- core_data->verbs 
  idx = rand_int_range(0, core_data->verbs_len);
  const char* verb_01 = core_data->verbs[idx]; 
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->verbs_len); }
  const char* verb_02 = core_data->verbs[idx];
  
  // -- core_data->nouns 
  idx = rand_int_range(0, core_data->nouns_len);
  const char* noun_01 = core_data->nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->nouns_len); }
  const char* noun_02 = core_data->nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->nouns_len); } 
  const char* noun_03 = core_data->nouns[idx];

  // -- core_data->adjectives 
  idx = rand_int_range(0, core_data->adjectives_len);
  const char* adj_01 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); }
  const char* adj_02 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); } 
  const char* adj_03 = core_data->adjectives[idx];

  // <pers> <genre01> <genre02> game 
  // where you <verb01> the <noun01> to <verb02> 
  // the <noun02> using the <noun03>
  _PF_COLOR(PF_PURPLE); PF("GAMEPLAY:\n"); _PF_COLOR(PF_WHITE);  
  PF("\t");
  _PF_COLOR(PERSPECTIVE_COLOR); PF("%s ", perspective); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(GENRE_COLOR);       PF("%s-", genre_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(GENRE_COLOR);       PF("%s ", genre_02); _PF_COLOR(PF_WHITE);  
  PF("game ");
  PF("\n\t");
  PF("where you ");
  _PF_COLOR(VERB_COLOR);        PF("%s ", verb_01); _PF_COLOR(PF_WHITE);  
  PF("the "); 
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_01); _PF_COLOR(PF_WHITE);  
  PF("to ");
  _PF_COLOR(VERB_COLOR);        PF("%s ", verb_02); _PF_COLOR(PF_WHITE);  
  PF("\n\t");
  PF("the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_02); _PF_COLOR(PF_WHITE);
  PF("using the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_03); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_03); _PF_COLOR(PF_WHITE);
  PF("\n");
}

void generator_print_setting()
{
  core_data_t* core_data = core_data_get();
  
  int idx = 0;
  int old_idx = 0;  // used when checking duplicates

  // -- core_data->settings 
  idx = rand_int_range(0, core_data->settings_len);
  // P_INT(idx);
  const char* setting_01 = core_data->settings[idx];
  // prevent two same core_data->settings
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->settings_len); }
  // P_INT(idx);
  const char* setting_02 = core_data->settings[idx];

  // -- core_data->themes 
  idx = rand_int_range(0, core_data->themes_len);
  // P_INT(idx);
  const char* theme_01 = core_data->themes[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->themes_len); }
  const char* theme_02 = core_data->themes[idx];
  
  // -- core_data->adjectives 
  idx = rand_int_range(0, core_data->adjectives_len);
  const char* adj_01 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); }
  const char* adj_02 = core_data->adjectives[idx];

  // a <setting01> world, with <setting02> elements 
  // and a visual theme of <theme>
  _PF_COLOR(PF_PURPLE); PF("SETTING:\n"); _PF_COLOR(PF_WHITE);  
  PF("\t");
  PF("a ");
  _PF_COLOR(SETTING_COLOR);     PF("%s ", setting_01); _PF_COLOR(PF_WHITE);  
  PF("world, with ");
  _PF_COLOR(SETTING_COLOR);     PF("%s ", setting_02); _PF_COLOR(PF_WHITE);  
  PF("elements");
  PF("\n\t");
  PF("and a visual theme of ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(THEME_COLOR);       PF("%s ", theme_01); _PF_COLOR(PF_WHITE);  
  PF("\n\t");
  PF("and ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(THEME_COLOR);       PF("%s ", theme_02); _PF_COLOR(PF_WHITE);  
  PF("\n");
}

void generator_print_story()
{
  core_data_t* core_data = core_data_get();
  
  int idx = 0;
  int old_idx = 0;  // used when checking duplicates

   // -- core_data->verbs 
  idx = rand_int_range(0, core_data->verbs_len);
  const char* verb_01 = core_data->verbs[idx]; 
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->verbs_len); }
  const char* verb_02 = core_data->verbs[idx];
  
  // -- core_data->nouns 
  idx = rand_int_range(0, core_data->nouns_len);
  const char* noun_01 = core_data->nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->nouns_len); }
  const char* noun_02 = core_data->nouns[idx]; 
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->nouns_len); }
  const char* noun_03 = core_data->nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->nouns_len); }
  const char* noun_04 = core_data->nouns[idx];

  // -- core_data->adjectives 
  idx = rand_int_range(0, core_data->adjectives_len);
  const char* adj_01 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); }
  const char* adj_02 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); }
  const char* adj_03 = core_data->adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, core_data->adjectives_len); }
  const char* adj_04 = core_data->adjectives[idx];

  // the antagonist, <adj01> <noun01>, has <verb01> the <adj02> <noun02>.
  // to save the <adj02> <noun02>, the protagonist, <adj03> <noun03>,
  // needs to <verb02> the <adj04> <noun04>
  _PF_COLOR(PF_PURPLE); PF("STORY:\n"); _PF_COLOR(PF_WHITE);  
  PF("\t");
  PF("the antagonist, ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s", noun_01); _PF_COLOR(PF_WHITE);
  PF(", has ");
  _PF_COLOR(VERB_COLOR);        PF("%sed ", verb_01); _PF_COLOR(PF_WHITE);  
  PF("the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_02); _PF_COLOR(PF_WHITE);
  PF("\n\t");
  PF("to save the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s", noun_02); _PF_COLOR(PF_WHITE);
  PF(", the protagonist, ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_03); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s", noun_03); _PF_COLOR(PF_WHITE);
  PF(", ");
  PF("\n\t");
  PF("needs to ");
  _PF_COLOR(VERB_COLOR);        PF("%s ", verb_02); _PF_COLOR(PF_WHITE);  
  PF("the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_04); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_04); _PF_COLOR(PF_WHITE);
  PF("\n");
}

segment_t generator_make_newline_segment()
{ return ((segment_t){ .type = SEG_NEWLINE, .idx = 0, .str = "" }); }
segment_t generator_make_string_segment(const char* str)
{ return ((segment_t){ .type = SEG_STRING, .idx = 0, .str = "hello" }); }

// @TODO: check dupliucates
segment_t generator_make_word_segment(segment_type type, int idx, int* idx_rtn)
{
  core_data_t* core_data = core_data_get();
  
  switch (type)
  {
    case SEG_PERSPECTIVE: 
      if (idx < 0) { idx = rand_int_range(0, core_data->perspectives_len); }
      if (idx_rtn != NULL) { *idx_rtn = idx; }
      return ((segment_t){ .type = SEG_PERSPECTIVE, .idx = idx, .str = "" });
    case SEG_GENRE: 
      break;
    case SEG_NOUN: 
      break;
    case SEG_VERB: 
      break;
    case SEG_ADJECTIVE: 
      break;
    case SEG_THEME: 
      break;
    case SEG_SETTING: 
      break;

    default:
      return ((segment_t){ .type = SEG_ERROR, .idx = -1, .str = "" });
  }
  
  // error
  return ((segment_t){ .type = SEG_ERROR, .idx = -1, .str = "" });
} 


void generator_print_segments(segment_t* arr, int len, const char* title)
{
  core_data_t* core_data = core_data_get();

  _PF_COLOR(PF_PURPLE); PF("%s:\n", title); _PF_COLOR(PF_WHITE);  
  PF("\t");
  
  for (int i = 0; i < len; ++i)
  {
    switch (arr[i].type)
    {
      case SEG_ERROR:
        _PF_COLOR(PF_RED); 
        PF("ERROR");
        _PF_COLOR(PF_WHITE);  
        
      case SEG_NEWLINE:
        PF("\n\t");
        break;
      case SEG_STRING:
        PF("%s", arr[i].str);
        break;

      case SEG_PERSPECTIVE: 
        _PF_COLOR(PERSPECTIVE_COLOR); 
        PF("%s", core_data->perspectives[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_GENRE: 
        _PF_COLOR(GENRE_COLOR); 
        PF("%s", core_data->genres[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_NOUN: 
        _PF_COLOR(NOUN_COLOR); 
        PF("%s", core_data->nouns[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_VERB: 
        _PF_COLOR(VERB_COLOR); 
        PF("%s", core_data->verbs[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_ADJECTIVE: 
        _PF_COLOR(ADJECTIVE_COLOR); 
        PF("%s", core_data->adjectives[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_THEME: 
        _PF_COLOR(THEME_COLOR); 
        PF("%s", core_data->themes[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
      case SEG_SETTING: 
        _PF_COLOR(SETTING_COLOR); 
        PF("%s", core_data->settings[arr[i].idx]);
        _PF_COLOR(PF_WHITE);  
        break;
    }
  }

  PF("\n");
}
