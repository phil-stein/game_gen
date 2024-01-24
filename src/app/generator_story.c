#include "app/generator.h"
#include "math/math_inc.h"


void generator_print_story()
{
  int x = rand_int_range(0, 2);

  switch (x)
  {
    case 0:
      generator_print_story_01();
      break;
    case 1:
      generator_print_story_02();
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
  VERB_PAST_TENSE(); 
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
  if (rand_bool())  // loveinterest
  {
    NEWLINE();
    PF("while trying to ");
    VERB(); 
    PF(" his love-interest the "); 
    LOVE_INTEREST();
  }
  PF("\n");
}

void generator_print_story_02()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("STORY");

  PF("the protagonist ");
  PROTAGONIST();
  PF(" has ");
  VERB_PAST_TENSE(); 
  PF(" the ");
  if (rand_bool()) { ADJECTIVE(); PF(" "); }
  NOUN();
  NEWLINE();
  ANTAGONIST();
  PF(", the antagonist,");
  NEWLINE();
  PF("is trying to stop him by ");
  VERB_ING_FORM(); 
  PF(" the ");
  if (rand_bool()) { ADJECTIVE(); PF(" "); }
  NOUN();
  if (rand_bool())  // which will cause the protagonist to
  {
    NEWLINE();
    PF("which will cause ");
    PROTAGONIST();
    PF(" to ");
    VERB();
    if (rand_bool()) { PF(" "); ADJECTIVE(); PF(" "); }
  }

  PF("\n");
}

