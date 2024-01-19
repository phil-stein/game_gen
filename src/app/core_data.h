#ifndef CORE_DATA_H
#define CORE_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "global/global.h"

typedef struct core_data_t
{
  bool style_act; // defines whether to print with color
}core_data_t;
#define CORE_DATA_INIT()            \
{                                   \
  .style_act = true,                \
}

core_data_t* core_data_get();


#ifdef __cplusplus
}   // extern c
#endif

#endif
