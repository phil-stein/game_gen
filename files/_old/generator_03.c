#include "app/generator.h"
#include "math/math_inc.h"


int* adjectives_used = NULL;
int  adjectives_used_len = 0;
int* nouns_used = NULL;
int  nouns_used_len = 0;
int* verbs_used = NULL;
int  verbs_used_len = 0;

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


void generator_reset_word_arrays()
{
  arrfree(adjectives_used);
  adjectives_used = NULL;
  adjectives_used_len = 0;
}

int ADJECTIVE() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->adjectives_len);
    is_duplicate = false;
    for (int i = 0; i < adjectives_used_len; ++i)
    {
      if (adjectives_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(adjectives_used, idx);
  adjectives_used_len++;
  
  const char* word = core_data->adjectives[idx];
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
int NOUN() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->nouns_len);
    is_duplicate = false;
    for (int i = 0; i < nouns_used_len; ++i)
    {
      if (nouns_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(nouns_used, idx);
  nouns_used_len++;
  
  const char* word = core_data->nouns[idx];
  _PF_COLOR(NOUN_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
int VERB() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->verbs_len);
    is_duplicate = false;
    for (int i = 0; i < verbs_used_len; ++i)
    {
      if (verbs_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(verbs_used, idx);
  verbs_used_len++;
  
  const char* word = core_data->verbs[idx];
  _PF_COLOR(VERB_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
void ADJECTIVE_IDX(int idx)
{
  core_data_t* core_data = core_data_get();
  const char* word = core_data->adjectives[idx];
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  
}
void NOUN_IDX(int idx)
{
  core_data_t* core_data = core_data_get();
  const char* word = core_data->nouns[idx];
  _PF_COLOR(NOUN_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  
}
void VERB_IDX(int idx)
{
  core_data_t* core_data = core_data_get();
  const char* word = core_data->verbs[idx];
  _PF_COLOR(VERB_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  
}

