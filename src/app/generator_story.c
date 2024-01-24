#include "app/generator.h"
#include "math/math_inc.h"


void generator_print_story()
{
  int x = rand_int_range(0, 3);

  switch (x)
  {
    case 0:
      generator_print_story_01();
      break;
    case 1:
      generator_print_story_02();
      break;
    case 2:
      generator_print_story_01();
      break;
    
    default:
      generator_print_story_01();
      break;
  }
}

void generator_print_story_01()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("STORY");

  PF("the antagonist, ");
  ANTAGONIST();
  PF(", has ");
  VERB(); 
  _PF_COLOR(VERB_COLOR); PF("ed"); _PF_COLOR(PF_WHITE);  
  PF(" the ");
  GOAL();
  PF("\n\t");
  PF("to save the ");
  GOAL();
  PF(", the protagonist, ");
  PROTAGONIST();
  PF(",");
  NEWLINE();
  PF("needs to ");
  VERB(); PF(" "); 
  PF("the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}

void generator_print_story_02()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("STORY");

  PF("the antagonist, ");
  ANTAGONIST();
  PF(", has ");
  VERB(); 
  _PF_COLOR(VERB_COLOR); PF("ed"); _PF_COLOR(PF_WHITE);  
  PF(" the ");
  GOAL();
  PF("\n\t");
  PF("to save the ");
  GOAL();
  PF(", the protagonist, ");
  PROTAGONIST();
  PF(",");
  NEWLINE();
  PF("needs to ");
  VERB(); PF(" "); 
  PF("the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  NEWLINE();
  PF("while trying to ");
  VERB(); 
  PF(" his love-interest the "); 
  LOVE_INTEREST();
  PF("\n");
}

