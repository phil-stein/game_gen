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

INLINE void TITLE(const char* title)
{
  core_data_t* core_data = core_data_get();
  _PF_COLOR(PF_PURPLE); PF("%s:\n", title); _PF_COLOR(PF_WHITE);  
  PF("\t");
}
#define NEWLINE() PF("\n\t") 


void ADJECTIVE_IDX(int idx);
void NOUN_IDX(int idx);
void VERB_IDX(int idx);

void generator_reset_word_arrays();

int generator_get_adjective();
int generator_get_noun();
int generator_get_verb();

int ADJECTIVE();
int NOUN();
int VERB();
int SETTING();
int THEME();
int PERSPECTIVE();
int GENRE();


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


#ifdef __cplusplus
}   // extern c
#endif

#endif  // GENERATOR_H
