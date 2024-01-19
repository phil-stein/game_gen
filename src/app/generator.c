#include "app/generator.h"
#include "math/math_inc.h"


int* adjectives_used = NULL;
int  adjectives_used_len = 0;
int* nouns_used = NULL;
int  nouns_used_len = 0;
int* verbs_used = NULL;
int  verbs_used_len = 0;
int* settings_used = NULL;
int  settings_used_len = 0;
int* themes_used = NULL;
int  themes_used_len = 0;
int* perspectives_used = NULL;
int  perspectives_used_len = 0;
int* genres_used = NULL;
int  genres_used_len = 0;


void generator_reset_word_arrays()
{
  arrfree(adjectives_used);
  adjectives_used = NULL;
  adjectives_used_len = 0;
  arrfree(nouns_used);
  nouns_used = NULL;
  nouns_used_len = 0;
  arrfree(verbs_used);
  verbs_used = NULL;
  verbs_used_len = 0;
  arrfree(settings_used);
  settings_used = NULL;
  settings_used_len = 0;
  arrfree(themes_used);
  themes_used = NULL;
  themes_used_len = 0;
  arrfree(perspectives_used);
  perspectives_used = NULL;
  perspectives_used_len = 0;
  arrfree(genres_used);
  genres_used = NULL;
  genres_used_len = 0;
}

void generator_print_gameplay()
{
  int x = rand_int_range(0, 3);

  switch (x)
  {
    case 0:
      generator_print_gameplay_01();
      break;
    case 1:
      generator_print_gameplay_02();
      break;
    case 2:
      generator_print_gameplay_03();
      break;
    
    default:
      generator_print_gameplay_01();
      break;
  }
}
void generator_print_setting()
{
  generator_print_setting_01();
}
void generator_print_story()
{
  generator_print_story_01();
}


void generator_print_setting_01()
{
  generator_reset_word_arrays();
  TITLE("SETTING");

  // a <setting01> world, with <setting02> elements 
  // and a visual theme of <theme>
  
  PF("a ");
  SETTING();
  PF(" world, with ");
  SETTING();
  PF(" elements");
  NEWLINE();
  PF("and a visual theme of ");
  ADJECTIVE(); PF(" ");
  THEME();
  NEWLINE();
  PF("and ");
  ADJECTIVE(); PF(" ");
  THEME();
  PF("\n");
}

void generator_print_story_01()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("STORY");

  PF("the antagonist, ");
  // int adj01  = ADJECTIVE(0); PF(" ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(", has ");
  VERB(); 
  _PF_COLOR(VERB_COLOR); PF("ed"); _PF_COLOR(PF_WHITE);  
  PF(" the ");
  // int adj02  = ADJECTIVE(1, adj01); PF(" ");
  int adj02 = ADJECTIVE(); PF(" ");
  int noun02 = NOUN();
  PF("\n\t");
  PF("to save the ");
  ADJECTIVE_IDX(adj02); PF(" ");
  NOUN_IDX(noun02);
  PF(", the protagonist, ");
  // int adj03  = ADJECTIVE(2, adj01, adj02); PF(" ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(",");
  NEWLINE();
  PF("needs to ");
  VERB(); PF(" "); 
  PF("the ");
  // int adj04  = ADJECTIVE(3, adj01, adj02, adj03); PF(" ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");

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
int SETTING() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->settings_len);
    is_duplicate = false;
    for (int i = 0; i < settings_used_len; ++i)
    {
      if (settings_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(settings_used, idx);
  settings_used_len++;
  
  const char* word = core_data->settings[idx];
  _PF_COLOR(SETTING_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
int THEME() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->themes_len);
    is_duplicate = false;
    for (int i = 0; i < themes_used_len; ++i)
    {
      if (themes_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(themes_used, idx);
  themes_used_len++;
  
  const char* word = core_data->themes[idx];
  _PF_COLOR(THEME_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
int PERSPECTIVE() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->perspectives_len);
    is_duplicate = false;
    for (int i = 0; i < perspectives_used_len; ++i)
    {
      if (perspectives_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(perspectives_used, idx);
  perspectives_used_len++;
  
  const char* word = core_data->perspectives[idx];
  _PF_COLOR(PERSPECTIVE_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  return idx;
}
int GENRE() 
{
  core_data_t* core_data = core_data_get();
 
  // generate new idx, check if duplicate
  int idx = -1;
  bool is_duplicate = false;
  do
  { 
    idx = rand_int_range(0, core_data->genres_len);
    is_duplicate = false;
    for (int i = 0; i < genres_used_len; ++i)
    {
      if (genres_used[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  
  arrput(genres_used, idx);
  genres_used_len++;
  
  const char* word = core_data->genres[idx];
  _PF_COLOR(GENRE_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

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

