#include "app/file_io.h"
#include "app/core_data.h"

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

#define _PF_COLOR(c)       if (core_data->style_act) { PF_COLOR((c)); }
#define _PF_STYLE(s, c)    if (core_data->style_act) { PF_STYLE((s), (c)); }
#define _PF_MODE_RESET()   if (core_data->style_act) { PF_MODE_RESET();  } 
#define _PF_STYLE_RESET()  if (core_data->style_act) { PF_STYLE_RESET(); }

#define _P_INT(var)                        \
  if (core_data->style_act) { P_INT(var); }   \
  else { PF("%s: %d\n", #var, (var)); }

// -- gameplay --
#define PERSPECTIVE_COLOR   PF_BLUE
#define GENRE_COLOR         PF_GREEN
#define VERB_COLOR          PF_CYAN
#define NOUN_COLOR          PF_RED
#define ADJECTIVE_COLOR     PF_YELLOW

// -- setting --
#define SETTING_COLOR       PF_GREEN
#define THEME_COLOR         PF_CYAN

void print_gameplay();
void print_setting();

const char* game_perspectives[] =
{
  "first-person",
  "third-person",
  "top-down"
};
const int game_perspectives_len = sizeof(game_perspectives) / sizeof(game_perspectives[0]);

const char* game_genres[] =
{
  "action",
  "puzzle",
  "shooter",
  "shoot-em-up",
  "adventure",
  "survival",
  "story-driven"
};
const int game_genres_len = sizeof(game_genres) / sizeof(game_genres[0]);

const char* verbs[] =
{
  "shoot",
  "find",
  "destroy",
  "repair",
  "move",
  "color"
};
const int verbs_len = sizeof(verbs) / sizeof(verbs[0]);

const char* nouns[] =
{
  "person",
  "alien",
  "house",
  "garden",
  "city",
  "man",
  "woman",
  "monster",
  "demon",
  "angel",
  "werewolf",
  "superhero"
};
const int nouns_len = sizeof(nouns) / sizeof(nouns[0]);

const char* adjectives[] =
{
  "big",
  "small",
  "round",
  "colorful",
  "tiny",
  "giant",
  "beautiful",
  "ugly",
  "sexy",
  "confusing",
  "religious",
  "cursed",
  "terrifying",
  "welcoming"
};
const int adjectives_len = sizeof(adjectives) / sizeof(adjectives[0]);

const char* settings[] =
{
  "modern",
  "sci-fi",
  "steampunk",
  "magepunk",
  "cyberpunk",
  "solarpunk",
  "fantasy",
  "dystopian",
  "utopian",
  "lovecraftian"
};
const int settings_len = sizeof(settings) / sizeof(settings[0]);

const char* themes[] =
{
  "realism",
  "nature",
  "machinery",
  "religion",
  "war",
  "poverty",
  "godhood"
};
const int themes_len = sizeof(themes) / sizeof(themes[0]);


int main(int argc, char** argv)
{
  core_data_t* core_data = core_data_get();
  
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

  print_gameplay();
 
  print_setting();

  PF("\n");
  _PF_COLOR(PF_PURPLE);
  P_LINE(); 
  _PF_COLOR(PF_WHITE);

  _PF_COLOR(PF_WHITE);
  _PF_STYLE_RESET();
	return 0;
}

void print_gameplay()
{
  core_data_t* core_data = core_data_get();
  
  int idx = 0;
  int old_idx = 0;  // used when checking duplicates
  
  // -- perspective
  idx = rand_int_range(0, game_perspectives_len);
  const char* perspective = game_perspectives[idx];
  
  // -- genres
  idx = rand_int_range(0, game_genres_len);
  const char* genre_01 = game_genres[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, game_genres_len); }
  const char* genre_02 = game_genres[idx];
  
  // -- verbs 
  idx = rand_int_range(0, verbs_len);
  const char* verb_01 = verbs[idx]; 
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, verbs_len); }
  const char* verb_02 = verbs[idx];
  
  // -- nouns 
  idx = rand_int_range(0, nouns_len);
  const char* noun_01 = nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, nouns_len); }
  const char* noun_02 = nouns[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, nouns_len); } 
  const char* noun_03 = nouns[idx];

  // -- adjectives 
  idx = rand_int_range(0, adjectives_len);
  const char* adj_01 = adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, adjectives_len); }
  const char* adj_02 = adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, adjectives_len); } 
  const char* adj_03 = adjectives[idx];

  // <pers> <genre01> <genre02> game 
  // where you <verb01> a/an/the <noun01> to <verb02> 
  // a/an/the <noun02> using the <noun03>
  _PF_COLOR(PF_PURPLE); PF("GAMEPLAY:\n"); _PF_COLOR(PF_WHITE);  
  PF("\t");
  _PF_COLOR(PERSPECTIVE_COLOR); PF("%s ", perspective); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(GENRE_COLOR);       PF("%s-", genre_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(GENRE_COLOR);       PF("%s ", genre_02); _PF_COLOR(PF_WHITE);  
  PF("game ");
  PF("\n\t");
  PF("where you ");
  _PF_COLOR(VERB_COLOR);        PF("%s ", verb_01); _PF_COLOR(PF_WHITE);  
  PF("a/an/the "); 
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_01); _PF_COLOR(PF_WHITE);  
  PF("to ");
  _PF_COLOR(VERB_COLOR);        PF("%s ", verb_02); _PF_COLOR(PF_WHITE);  
  PF("\n\t");
  PF("a/an/the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_02); _PF_COLOR(PF_WHITE);
  PF("using the ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_03); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(NOUN_COLOR);        PF("%s ", noun_03); _PF_COLOR(PF_WHITE);
  PF("\n");
}

void print_setting()
{
  core_data_t* core_data = core_data_get();
  
  int idx = 0;
  int old_idx = 0;  // used when checking duplicates

  // -- settings 
  idx = rand_int_range(0, settings_len);
  // P_INT(idx);
  const char* setting_01 = settings[idx];
  // prevent two same settings
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, settings_len); }
  // P_INT(idx);
  const char* setting_02 = settings[idx];

  // -- themes 
  idx = rand_int_range(0, themes_len);
  // P_INT(idx);
  const char* theme_01 = themes[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, themes_len); }
  const char* theme_02 = themes[idx];
  
  // -- adjectives 
  idx = rand_int_range(0, adjectives_len);
  const char* adj_01 = adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, adjectives_len); }
  const char* adj_02 = adjectives[idx];
  old_idx = idx;
  while (idx == old_idx) { idx = rand_int_range(0, adjectives_len); } 
  const char* adj_03 = adjectives[idx];

  // a <setting01> world, with <setting02> elements 
  // and a visual theme of <theme>
  _PF_COLOR(PF_PURPLE); PF("SETTING:\n"); _PF_COLOR(PF_WHITE);  
  PF("\t");
  PF("a ");
  _PF_COLOR(SETTING_COLOR);     PF("%s ", setting_01); _PF_COLOR(PF_WHITE);  
  PF("world, with ");
  _PF_COLOR(SETTING_COLOR);     PF("%s ", setting_02); _PF_COLOR(PF_WHITE);  
  PF("elements");
  PF("\n\t");
  PF("and a visual theme of ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_01); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(THEME_COLOR);       PF("%s ", theme_01); _PF_COLOR(PF_WHITE);  
  PF("\n\t");
  PF("and ");
  _PF_COLOR(ADJECTIVE_COLOR);   PF("%s ", adj_02); _PF_COLOR(PF_WHITE);  
  _PF_COLOR(THEME_COLOR);       PF("%s ", theme_02); _PF_COLOR(PF_WHITE);  
  PF("\n");
}

