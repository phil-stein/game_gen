#include "app/file_io.h"
#include "app/core_data.h"
#include "app/generator.h"

#include "math/math_inc.h"

// order is important, io_util & str_util before global
#define IO_UTIL_IMPLEMENTATION       // only define once
#include "global/io_util.h"          // only need to include here, normally included via global.h
#define STR_UTIL_IMPLEMENTATION      // only define once
#include "global/str_util.h"         // only need to include here, normally included via global.h
#include "global/global.h"

#define STB_DS_IMPLEMENTATION   // only define once
#include "stb/stb_ds.h"

// #include <ctype.h>
// #include <direct.h>
// #include <dirent/dirent.h>

#include <time.h>


int main(int argc, char** argv)
{
  core_data_t* core_data = core_data_get();
  core_data_init();
  
  // make random seed based on time
  u64 time64 = time(NULL);
  u32 time32 = (u32)(time64 - 1705674400);
  time32 *= 423;
  rand_seed(time32);
  // PF("time64: %ld\n", time64);
  // PF("time32: %d\n", time32);
  
  
  // --- printing ---

  _PF_COLOR(PF_PURPLE);
  P_LINE_STR("rnd game gen "); 
  _PF_COLOR(PF_WHITE);
  PF("\n");

  generator_print_gameplay();
  generator_print_setting();
  generator_print_story();

  segment_t* seg_arr = NULL;
  int        seg_arr_len = 0;
  
  arrput(seg_arr, generator_make_string_segment("hello")); seg_arr_len++;
  arrput(seg_arr, generator_make_newline_segment()); seg_arr_len++;
  
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, -1, NULL)); seg_arr_len++;
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, -1, NULL)); seg_arr_len++;
  int pers01;
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, -1, &pers01)); seg_arr_len++;
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, pers01, NULL)); seg_arr_len++;
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, pers01, NULL)); seg_arr_len++;
  arrput(seg_arr, generator_make_word_segment(SEG_PERSPECTIVE, pers01, NULL)); seg_arr_len++;

  generator_print_segments(seg_arr, seg_arr_len, "TEST");

  PF("\n");
  _PF_COLOR(PF_PURPLE);
  P_LINE(); 
  _PF_COLOR(PF_WHITE);

  core_data_cleanup();

  _PF_COLOR(PF_WHITE);
  _PF_STYLE_RESET();
	return 0;
}

