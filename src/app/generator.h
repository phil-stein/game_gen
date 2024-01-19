#ifndef GENERATOR_H
#define GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "global/global.h"
#include "app/core_data.h"

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

void generator_print_gameplay();
void generator_print_setting();
void generator_print_story();


#ifdef __cplusplus
}   // extern c
#endif

#endif  // GENERATOR_H
