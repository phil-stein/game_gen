#ifndef CORE_DATA_H
#define CORE_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "global/global.h"

typedef struct core_data_t
{
  bool style_act; // defines whether to print with color
  
  char** perspectives;     // needs to be arrfree'd
  int    perspectives_len;
  char*  perspectives_txt; // the txt from the file, needs to be free'd

  char** genres;     // needs to be arrfree'd
  int    genres_len;
  char*  genres_txt; // the txt from the file, needs to be free'd
  
  char** verbs;     // needs to be arrfree'd
  int    verbs_len;
  char*  verbs_txt; // the txt from the file, needs to be free'd
  
  char** nouns;     // needs to be arrfree'd
  int    nouns_len;
  char*  nouns_txt; // the txt from the file, needs to be free'd
  
  char** adjectives;     // needs to be arrfree'd
  int    adjectives_len;
  char*  adjectives_txt; // the txt from the file, needs to be free'd
    
  char** settings;     // needs to be arrfree'd
  int    settings_len;
  char*  settings_txt; // the txt from the file, needs to be free'd

  char** themes;     // needs to be arrfree'd
  int    themes_len;
  char*  themes_txt; // the txt from the file, needs to be free'd
  
  char** twists;     // needs to be arrfree'd
  int    twists_len;
  char*  twists_txt; // the txt from the file, needs to be free'd

  int goal_adj;
  int goal_noun;
  int antagonist_adj;
  int antagonist_noun;
  int protagonist_adj;
  int protagonist_noun;
  int love_interest_adj;
  int love_interest_noun;

}core_data_t;
#define CORE_DATA_INIT()            \
{                                   \
  .style_act = true,                \
  .goal_adj  = 0,                   \
  .goal_noun = 0,                   \
  .antagonist_adj  = 0,             \
  .antagonist_noun = 0,             \
  .protagonist_adj  = 0,            \
  .protagonist_noun = 0,            \
  .love_interest_adj  = 0,          \
  .love_interest_noun = 0,          \
}

core_data_t* core_data_get();
void core_data_init();
void core_data_cleanup();
void core_data_read_file(const char* file_path, char* txt, char*** arr, int* len);
void core_data_check_duplicates_named(char** arr, int len, const char* name);
#define core_data_check_duplicates(arr, len) core_data_check_duplicates_named((arr), (len), #arr)


#define GOAL_PTR(_core_data)                        \
  ADJECTIVE_IDX((_core_data)->goal_adj); PF(" ");   \
  NOUN_IDX((_core_data)->goal_noun);

#define ANTAGONIST_PTR(_core_data)                       \
  ADJECTIVE_IDX((_core_data)->antagonist_adj); PF(" ");  \
  NOUN_IDX((_core_data)->antagonist_noun);

#define PROTAGONIST_PTR(_core_data)                       \
  ADJECTIVE_IDX((_core_data)->protagonist_adj); PF(" ");  \
  NOUN_IDX((_core_data)->protagonist_noun);

#define LOVE_INTEREST_PTR(_core_data)                       \
  ADJECTIVE_IDX((_core_data)->love_interest_adj); PF(" ");  \
  NOUN_IDX((_core_data)->love_interest_noun);

#define GOAL()           GOAL_PTR(core_data) 
#define ANTAGONIST()     ANTAGONIST_PTR(core_data)                             
#define PROTAGONIST()    PROTAGONIST_PTR(core_data)                            
#define LOVE_INTEREST()  LOVE_INTEREST_PTR(core_data)                               

#ifdef __cplusplus
}   // extern c
#endif

#endif
