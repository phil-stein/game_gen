#include "app/generator.h"
#include "math/math_inc.h"


void generator_print_gameplay_01()
{
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
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(" to ");
  VERB();
  NEWLINE();
  PF("the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}
void generator_print_gameplay_02()
{
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
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(" to ");
  VERB();
  NEWLINE();
  PF("the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(" using the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}
void generator_print_gameplay_03()
{
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
  ADJECTIVE(); PF(" ");
  NOUN();
  PF(" to ");
  VERB();
  NEWLINE(); // the <adj02> <noun02> using the <noun03>
  PF("the ");
  int adj02 = ADJECTIVE(); PF(" ");
  int noun02 = NOUN();
  PF(" using the ");
  ADJECTIVE(); PF(" ");
  NOUN();
  NEWLINE(); // the <adj02> <noun02> is immune to <adj03> <noun04>
  ADJECTIVE_IDX(adj02); PF(" ");
  NOUN_IDX(noun02);
  PF(" is immune to ");
  ADJECTIVE(); PF(" ");
  NOUN();
  PF("\n");
}
