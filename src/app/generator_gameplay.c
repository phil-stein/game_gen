#include "app/generator.h"
#include "math/math_inc.h"
#include "app/core_data.h"


void generator_print_gameplay()
{
 
  int x = rand_int_range(0, 2);
  switch (x)
  {
    case 0:
      generator_print_gameplay_01();
      break;
    case 1:
      generator_print_gameplay_02();
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

  int  genres_count = rand_int_range(1, MIN(core_data->genres_len, 3));
  // PF("genres_count: %d, print_tool: %s, print_twist: %s", genres_count, STR_BOOL(print_tool), STR_BOOL(print_twist)); NEWLINE();

  // <pers> <genre01>-<genre02>-<genre03> game 
  // where you <verb01> the <adj01> <noun01> to <verb02> 
  // the <adj02> <noun02> using the <noun03>
  // the <adj02> <noun02> is immune to <adj03> <noun04>
  // with a twist of <twist01>
  PERSPECTIVE(); PF(" ");
  for (int i = 0; i < genres_count; ++i) 
  { GENRE();  PF("%s", i == genres_count -1 ? " " : "-"); }
  PF("game ");
  NEWLINE(); // where you <verb01> the <adj01> <noun01> to <verb02> 
  PF("where you ");
  VERB();
  PF(" the "); 
  GOAL();
  PF(" to ");
  VERB();
  NEWLINE(); // the <antagonist> using the <noun03>
  PF("the ");
  ANTAGONIST();
  if (rand_bool())  // tool
  {
    PF(" using the ");
    ADJECTIVE(); PF(" ");
    NOUN();
  }
  if (rand_bool()) // immune
  {
    NEWLINE(); // the <antagonist> is immune to <adj03> <noun04>
    ANTAGONIST();
    PF(" is immune to ");
    ADJECTIVE(); PF(" ");
    NOUN();
  }
  if (rand_bool())  // twist
  {
    NEWLINE(); // with a twist of <adj> <twist01> and <twist>
    PF("with a twist of ");
    if (rand_bool()) { ADJECTIVE(); PF(" "); }
    TWIST();
    if (rand_bool()) 
    { 
      PF(" and ");
      if (rand_bool()) { ADJECTIVE(); PF(" "); }
      TWIST();
    }
  }
  PF("\n");
}

void generator_print_gameplay_02()
{
  core_data_t* core_data = core_data_get();

  generator_reset_word_arrays();
  TITLE("GAMEPLAY");

  int  genres_count     = rand_int_range(3, MIN(core_data->genres_len, 6));
  int  objectives_count = rand_int_range(3, 6);
  // PF("genres_count: %d, print_tool: %s, print_twist: %s", genres_count, STR_BOOL(print_tool), STR_BOOL(print_twist)); NEWLINE();

  // <pers> <genre> - ... - <genre> game
  // <verb> the <noun>
  // <verb> the <noun>
  // <verb> the <noun>
  PERSPECTIVE(); PF(" ");
  for (int i = 0; i < genres_count; ++i) 
  { GENRE();  PF("%s", i == genres_count -1 ? " " : "-"); }
  PF("game ");
  
  for (int i = 0; i < objectives_count; ++i) 
  {
    NEWLINE();
    PF("%d. ", i+1);
    VERB(); PF(" ");
    if (rand_bool()) { ADJECTIVE(); PF(" "); }
    NOUN();
  }

  if (rand_bool())  // twist
  {
    NEWLINE(); // with a twist of <adj> <twist01> and <twist>
    PF("with a twist of ");
    TWIST();
    if (rand_bool()) 
    { 
      PF(" and ");
      TWIST();
    }
  }
  PF("\n");
}
