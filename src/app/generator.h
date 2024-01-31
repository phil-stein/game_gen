#ifndef GENERATOR_H
#define GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "global/global.h"
#include "app/core_data.h"
#include "math/math_inc.h"

#include "stb/stb_ds.h"

#include <stdarg.h>

#define _PF_COLOR(c)       if (core_data->style_act) { PF_COLOR((c)); }
#define _PF_STYLE(s, c)    if (core_data->style_act) { PF_STYLE((s), (c)); }
#define _PF_MODE_RESET()   if (core_data->style_act) { PF_MODE_RESET();  } 
#define _PF_STYLE_RESET()  if (core_data->style_act) { PF_STYLE_RESET(); }

#define _P_INT(var)                        \
  if (core_data->style_act) { P_INT(var); }   \
  else { PF("%s: %d\n", #var, (var)); }

// -- gameplay --
#define PERSPECTIVE_COLOR   PF_BLUE
#define GENRE_COLOR         PF_GREEN
#define VERB_COLOR          PF_CYAN
#define NOUN_COLOR          PF_RED
#define ADJECTIVE_COLOR     PF_YELLOW

// -- setting --
#define SETTING_COLOR       PF_GREEN
#define THEME_COLOR         PF_CYAN


#define TWIST_COLOR         PF_CYAN

INLINE void TITLE(const char* title)
{
  core_data_t* core_data = core_data_get();
  _PF_COLOR(PF_PURPLE); PF("%s:\n", title); _PF_COLOR(PF_WHITE);  
  PF("\t");
}
#define NEWLINE() PF("\n\t") 

// --- templates ---

#define GENERATOR_USED_ARR_DECL(name) \
  int* name##_used = NULL;            \
  int  name##_used_len = 0;

#define GENERATOR_USED_ARR_CLEAR(name)      \
  if(name##_used) { arrfree(name##_used); } \
  name##_used = NULL;                       \
  name##_used_len = 0;

#define GENERATOR_GET_TEMPLATE_DECL(name, arr_name)                     \
int generator_get_##name()                                              

#define GENERATOR_GET_TEMPLATE(name, arr_name)                          \
int generator_get_##name()                                              \
{                                                                       \
  core_data_t* core_data = core_data_get();                             \
                                                                        \
  /* generate new idx, check if duplicate */                            \
  int idx = -1;                                                         \
  bool is_duplicate = false;                                            \
  do                                                                    \
  {                                                                     \
    idx = rand_int_range(0, core_data->arr_name##_len);                 \
    is_duplicate = false;                                               \
    /* reset arr if full */                                             \
    if (arr_name##_used_len >= core_data->arr_name##_len)               \
    { GENERATOR_USED_ARR_CLEAR(arr_name); }                             \
    else                                                                \
    {                                                                   \
      for (int i = 0; i < arr_name##_used_len; ++i)                     \
      {                                                                 \
        if (arr_name##_used[i] == idx) { is_duplicate = true; break; }  \
      }                                                                 \
    }                                                                   \
  }                                                                     \
  while (is_duplicate);                                                 \
                                                                        \
  arrput(arr_name##_used, idx);                                         \
  arr_name##_used_len++;                                                \
                                                                        \
  return idx;                                                           \
}

#define GENERATOR_WORD_TEMPLATE_DECL(name)  \
int name()

#define GENERATOR_WORD_TEMPLATE(name, get_func_name, arr_name, _color)  \
int name()                                                              \
{                                                                       \
  core_data_t* core_data = core_data_get();                             \
  int idx = generator_get_##get_func_name();                            \
  const char* word = core_data->arr_name[idx];                          \
  _PF_COLOR(_color);   PF("%s", word); _PF_COLOR(PF_WHITE);             \
  return idx;                                                           \
}

#define GENERATOR_WORD_IDX_TEMLPLATE_DECL(name)   \
void name##_IDX(int idx)

#define GENERATOR_WORD_IDX_TEMLPLATE(name, arr_name, color)   \
void name##_IDX(int idx)                                      \
{                                                             \
  core_data_t* core_data = core_data_get();                   \
  const char* word = core_data->arr_name[idx];                \
  _PF_COLOR(color);   PF("%s", word); _PF_COLOR(PF_WHITE);    \
}


void generator_reset_word_arrays();

// generator_get_...() funcs
GENERATOR_GET_TEMPLATE_DECL(adjective, adjectives);
GENERATOR_GET_TEMPLATE_DECL(noun, nouns);
GENERATOR_GET_TEMPLATE_DECL(verb, verbs);
GENERATOR_GET_TEMPLATE_DECL(setting, settings);
GENERATOR_GET_TEMPLATE_DECL(theme, themes);
GENERATOR_GET_TEMPLATE_DECL(perspective, perspectives);
GENERATOR_GET_TEMPLATE_DECL(genre, genres);
GENERATOR_GET_TEMPLATE_DECL(twist, twists);

// ...() funcs
GENERATOR_WORD_TEMPLATE_DECL(ADJECTIVE);
GENERATOR_WORD_TEMPLATE_DECL(NOUN);
GENERATOR_WORD_TEMPLATE_DECL(VERB);
GENERATOR_WORD_TEMPLATE_DECL(SETTING);
GENERATOR_WORD_TEMPLATE_DECL(THEME);
GENERATOR_WORD_TEMPLATE_DECL(PERSPECTIVE);
GENERATOR_WORD_TEMPLATE_DECL(GENRE);
GENERATOR_WORD_TEMPLATE_DECL(TWIST);

// ..._IDX() funcs
GENERATOR_WORD_IDX_TEMLPLATE_DECL(ADJECTIVE);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(NOUN);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(VERB);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(SETTING);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(THEME);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(PERSPECTIVE);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(GENRE);
GENERATOR_WORD_IDX_TEMLPLATE_DECL(TWIST);

int  VERB_PAST_TENSE(); 
void VERB_IDX_PAST_TENSE(int idx); 
int  VERB_ING_FORM(); 
void VERB_IDX_ING_FORM(int idx); 

void generator_print_gameplay();
void generator_print_setting();
void generator_print_story();

void generator_print_gameplay_01();
void generator_print_gameplay_02();
void generator_print_gameplay_03();
void generator_print_setting_01();
void generator_print_setting_02();
void generator_print_setting_03();
void generator_print_story_01();
void generator_print_story_02();


#ifdef __cplusplus
}   // extern c
#endif

#endif  // GENERATOR_H
