#include "app/generator.h"
#include "math/math_inc.h"
#include "app/core_data.h"


void generator_print_gameplay()
{
  int x = rand_int_range(0, 3);

  switch (x)
  {
    case 0:
      generator_print_gameplay_01();
      break;
    case 1:
      generator_print_gameplay_02();
      break;
    case 2:
      generator_print_gameplay_03();
      break;
    
    default:
      generator_print_gameplay_01();
      break;
  }
}

void generator_print_gameplay_01()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("GAMEPLAY");

  // <pers> <genre01> game 
  // where you <verb01> the <noun01> to <verb02> 
  // the <noun02> 
  PERSPECTIVE(); PF(" ");
  GENRE();  PF(" ");
  PF("game ");
  NEWLINE();
  PF("where you ");
  VERB();
  PF(" the "); 
  GOAL();
  PF(" to ");
  VERB();
  NEWLINE();
  PF("the ");
  ANTAGONIST();
  PF("\n");
}
void generator_print_gameplay_02()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("GAMEPLAY");

  // <pers> <genre01> <genre02> game 
  // where you <verb01> the <noun01> to <verb02> 
  // the <noun02> using the <noun03>
  PERSPECTIVE(); PF(" ");
  GENRE();  PF("-");
  GENRE();  PF(" ");
  PF("game ");
  NEWLINE();
  PF("where you ");
  VERB();
  PF(" the "); 
  GOAL();
  PF(" to ");
  VERB();
  NEWLINE();
  PF("the ");
  ANTAGONIST();
  PF(" using the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}
void generator_print_gameplay_03()
{
  core_data_t* core_data = core_data_get();
  
  generator_reset_word_arrays();
  TITLE("GAMEPLAY");

  // <pers> <genre01>-<genre02>-<genre03> game 
  // where you <verb01> the <adj01> <noun01> to <verb02> 
  // the <adj02> <noun02> using the <noun03>
  // the <adj02> <noun02> is immune to <adj03> <noun04>
  PERSPECTIVE(); PF(" ");
  GENRE();  PF("-");
  GENRE();  PF("-");
  GENRE();  PF(" ");
  PF("game ");
  NEWLINE(); // where you <verb01> the <adj01> <noun01> to <verb02> 
  PF("where you ");
  VERB();
  PF(" the "); 
  GOAL();
  PF(" to ");
  VERB();
  NEWLINE(); // the <adj02> <noun02> using the <noun03>
  PF("the ");
  ANTAGONIST();
  PF(" using the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  NEWLINE(); // the <adj02> <noun02> is immune to <adj03> <noun04>
  ANTAGONIST();
  PF(" is immune to ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}
