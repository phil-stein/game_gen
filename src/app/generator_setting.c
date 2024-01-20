#include "app/generator.h"
#include "math/math_inc.h"


void generator_print_setting()
{
  int x = rand_int_range(0, 3);

  switch (x)
  {
    case 0:
      generator_print_setting_01();
      break;
    case 1:
      generator_print_setting_02();
      break;
    case 2:
      generator_print_setting_03();
      break;
    
    default:
      generator_print_setting_01();
      break;
  }
}


void generator_print_setting_01()
{
  generator_reset_word_arrays();
  TITLE("SETTING");

  // a <setting01> world, with <setting02> elements 
  // and a visual theme of <adj01> <theme>
  
  PF("a ");
  SETTING();
  PF(" world, with ");
  SETTING();
  PF(" elements");
  NEWLINE();
  PF("and a visual theme of ");
  ADJECTIVE(); PF(" ");
  THEME();
  NEWLINE();
  PF("and ");
  ADJECTIVE(); PF(" ");
  THEME();
  PF("\n");
}

void generator_print_setting_02()
{
  generator_reset_word_arrays();
  TITLE("SETTING");

  // a <setting01>-<setting02> world, 
  // with <setting03> elements 
  // and a visual theme of <adj01> <adj02> <theme01>
  // and <adj03> <theme02>
  
  PF("a ");
  SETTING(); PF("-");
  SETTING();
  PF(" world,");
  NEWLINE();  // with <setting03> elements
  PF("with ");
  SETTING();
  PF(" elements");
  NEWLINE(); // and a visual theme of <adj01> <theme>
  PF("and a visual theme of ");
  ADJECTIVE(); PF(" ");
  ADJECTIVE(); PF(" ");
  THEME();
  NEWLINE();
  PF("and ");
  ADJECTIVE(); PF(" ");
  THEME();
  PF("\n");
}


void generator_print_setting_03()
{
  generator_reset_word_arrays();
  TITLE("SETTING");

  // a <setting01>-<setting02> world, 
  // with <adj01> <setting03> elements 
  // and a visual theme of <adj02> <theme01>
  // defined by <adj03> <theme02>
  // and <adj04> <theme03>
  
  PF("a ");
  SETTING(); PF("-");
  SETTING();
  PF(" world,");
  NEWLINE();  // with <setting03> elements
  PF("with ");
  ADJECTIVE(); PF(" ");
  SETTING();
  PF(" elements");
  NEWLINE(); // and a visual theme of <adj01> <theme>
  PF("and a visual theme of ");
  ADJECTIVE(); PF(" ");
  THEME();
  NEWLINE();   // <verb01> by <adj03> <theme02>
  PF("defined by ");
  ADJECTIVE(); PF(" ");
  THEME();
  NEWLINE();  // and <adj04> <theme03>
  PF("and ");
  ADJECTIVE(); PF(" ");
  THEME();
  PF("\n");
}
