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
  // ADJECTIVE(); PF(" ");
  // NOUN();
  ADJECTIVE_IDX(core_data->antagonist_adj); PF(" ");
  NOUN_IDX(core_data->antagonist_noun);
  PF(", has ");
  VERB(); 
  _PF_COLOR(VERB_COLOR); PF("ed"); _PF_COLOR(PF_WHITE);  
  PF(" the ");
  // int adj02 = ADJECTIVE(); PF(" ");
  // int noun02 = NOUN();
  ADJECTIVE_IDX(core_data->goal_adj); PF(" ");
  NOUN_IDX(core_data->goal_noun);
  PF("\n\t");
  PF("to save the ");
  // ADJECTIVE_IDX(adj02); PF(" ");
  // NOUN_IDX(noun02);
  ADJECTIVE_IDX(core_data->goal_adj); PF(" ");
  NOUN_IDX(core_data->goal_noun);
  PF(", the protagonist, ");
  // ADJECTIVE(); PF(" ");
  // NOUN();
  ADJECTIVE_IDX(core_data->protagonist_adj); PF(" ");
  NOUN_IDX(core_data->protagonist_noun);
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
  // ADJECTIVE(); PF(" ");
  // NOUN();
  ADJECTIVE_IDX(core_data->antagonist_adj); PF(" ");
  NOUN_IDX(core_data->antagonist_noun);
  PF(", has ");
  VERB(); 
  _PF_COLOR(VERB_COLOR); PF("ed"); _PF_COLOR(PF_WHITE);  
  PF(" the ");
  // int adj02 = ADJECTIVE(); PF(" ");
  // int noun02 = NOUN();
  ADJECTIVE_IDX(core_data->goal_adj); PF(" ");
  NOUN_IDX(core_data->goal_noun);
  PF("\n\t");
  PF("to save the ");
  // ADJECTIVE_IDX(adj02); PF(" ");
  // NOUN_IDX(noun02);
  ADJECTIVE_IDX(core_data->goal_adj); PF(" ");
  NOUN_IDX(core_data->goal_noun);
  PF(", the protagonist, ");
  // ADJECTIVE(); PF(" ");
  // NOUN();
  ADJECTIVE_IDX(core_data->protagonist_adj); PF(" ");
  NOUN_IDX(core_data->protagonist_noun);
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
  // ADJECTIVE(); PF(" ");
  // NOUN();
  ADJECTIVE_IDX(core_data->love_interest_adj); PF(" ");
  NOUN_IDX(core_data->love_interest_noun);
  PF("\n");
}

