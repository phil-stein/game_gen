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
  // make random seed based on time
  u64 time64 = time(NULL);
  u32 time32 = (u32)(time64 - 1705674400);
  time32 *= 423;
  rand_seed(time32);
  // PF("time64: %ld\n", time64);
  // PF("time32: %d\n", time32);
 
  core_data_t* core_data = core_data_get();
  core_data_init();

  
  // --- cmd args ---
  for (int i = 1; i < argc; ++i)
  {
    // commands
    if (argv[i][0] == '-')
    {
      // -c -> no syntax highlighting
      if (argv[i][1] == 'c')
      {
        core_data->style_act = false;
      }
    }
  }


  // --- printing ---

  // // @TMP: testing past tense verbs
  // for (int i = 0; i < core_data->verbs_len; ++i)
  // {
  //   VERB_IDX_PAST_TENSE(i); PF(" ");
  // }
  // PF("\n");
  // @TMP: testing the -ing forms
  // for (int i = 0; i < core_data->verbs_len; ++i)
  // {
  //   VERB_IDX_ING_FORM(i); PF(" ");
  // }
  // PF("\n");
  
  _PF_COLOR(PF_PURPLE);
  P_LINE_STR("rnd game gen "); 
  _PF_COLOR(PF_WHITE);
  PF("\n");
  
  TITLE("STATS");
  PF("GOAL:          "); GOAL();          NEWLINE();
  PF("ANTAGONIST:    "); ANTAGONIST();    NEWLINE();
  PF("PROTAGONIST:   "); PROTAGONIST();   NEWLINE();
  PF("LOVE_INTEREST: "); LOVE_INTEREST(); NEWLINE();
  PF("\n");

  generator_print_gameplay();
  generator_print_setting();
  generator_print_story();

  PF("\n");
  _PF_COLOR(PF_PURPLE);
  P_LINE(); 
  _PF_COLOR(PF_WHITE);

  core_data_cleanup();

  _PF_COLOR(PF_WHITE);
  _PF_STYLE_RESET();
	return 0;
}

