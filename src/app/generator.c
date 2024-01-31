#include "app/generator.h"
#include "math/math_inc.h"


// ..._used arrs decls
GENERATOR_USED_ARR_DECL(adjectives);
GENERATOR_USED_ARR_DECL(nouns);
GENERATOR_USED_ARR_DECL(verbs);
GENERATOR_USED_ARR_DECL(settings);
GENERATOR_USED_ARR_DECL(themes);
GENERATOR_USED_ARR_DECL(perspectives);
GENERATOR_USED_ARR_DECL(genres);
GENERATOR_USED_ARR_DECL(twists);


void generator_reset_word_arrays()
{
  // clear ..._used arrs
  GENERATOR_USED_ARR_CLEAR(adjectives);
  GENERATOR_USED_ARR_CLEAR(nouns);
  GENERATOR_USED_ARR_CLEAR(verbs);
  GENERATOR_USED_ARR_CLEAR(settings);
  GENERATOR_USED_ARR_CLEAR(themes);
  GENERATOR_USED_ARR_CLEAR(perspectives);
  GENERATOR_USED_ARR_CLEAR(genres);
  GENERATOR_USED_ARR_CLEAR(twists);
}

// generator_get...(), ...() and ..._IDX() functions

GENERATOR_GET_TEMPLATE(adjective, adjectives);
GENERATOR_WORD_TEMPLATE(ADJECTIVE, adjective, adjectives, ADJECTIVE_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(ADJECTIVE, adjectives, ADJECTIVE_COLOR);

GENERATOR_GET_TEMPLATE(noun, nouns);
GENERATOR_WORD_TEMPLATE(NOUN, noun, nouns, NOUN_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(NOUN, nouns, NOUN_COLOR);

GENERATOR_GET_TEMPLATE(verb, verbs);
GENERATOR_WORD_TEMPLATE(VERB, verb, verbs, VERB_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(VERB, verbs, VERB_COLOR);

GENERATOR_GET_TEMPLATE(setting, settings);
GENERATOR_WORD_TEMPLATE(SETTING, setting, settings, SETTING_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(SETTING, settings, SETTING_COLOR);

GENERATOR_GET_TEMPLATE(theme, themes);
GENERATOR_WORD_TEMPLATE(THEME, theme, themes, THEME_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(THEME, themes, THEME_COLOR);

GENERATOR_GET_TEMPLATE(perspective, perspectives);
GENERATOR_WORD_TEMPLATE(PERSPECTIVE, perspective, perspectives, PERSPECTIVE_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(PERSPECTIVE, perspectives, PERSPECTIVE_COLOR);

GENERATOR_GET_TEMPLATE(genre, genres);
GENERATOR_WORD_TEMPLATE(GENRE, genre, genres, GENRE_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(GENRE, genres, GENRE_COLOR);

GENERATOR_GET_TEMPLATE(twist, twists);
GENERATOR_WORD_TEMPLATE(TWIST, twist, twists, TWIST_COLOR);
GENERATOR_WORD_IDX_TEMLPLATE(TWIST, twists, TWIST_COLOR);

int VERB_PAST_TENSE() 
{
  int idx = generator_get_verb();
  VERB_IDX_PAST_TENSE(idx);
  return idx; 
}
void VERB_IDX_PAST_TENSE(int idx) 
{
  core_data_t* core_data = core_data_get();                   
  const char* word = core_data->verbs[idx];
  
  const int PAST_TENSE_MAX = 128;
  char past_tense[PAST_TENSE_MAX];
  STRCPY(past_tense, word);

  if      (!strcmp(past_tense, "shoot"))    { STRCPY(past_tense, "shot"); } 
  else if (!strcmp(past_tense, "find"))     { STRCPY(past_tense, "found"); } 
  else if (!strcmp(past_tense, "steal"))    { STRCPY(past_tense, "stole"); }
  else if (!strcmp(past_tense, "ride"))     { STRCPY(past_tense, "rode"); }
  else if (!strcmp(past_tense, "overcome")) { STRCPY(past_tense, "overcome"); }
  else if (past_tense[strlen(past_tense) -1] == 'e')  // last char alread e, i.e. moved
  { strcat(past_tense, "d"); } 
  else { strcat(past_tense, "ed"); }

  _PF_COLOR(VERB_COLOR);   PF("%s", past_tense); _PF_COLOR(PF_WHITE);    
}

int VERB_ING_FORM() 
{
  int idx = generator_get_verb();
  VERB_IDX_ING_FORM(idx);
  return idx;
}
void VERB_IDX_ING_FORM(int idx) 
{
  core_data_t* core_data = core_data_get();                   
  const char* word = core_data->verbs[idx];
  
  const int PAST_TENSE_MAX = 128;
  char past_tense[PAST_TENSE_MAX];
  STRCPY(past_tense, word);

  if (past_tense[strlen(past_tense) -1] == 'e')  // last char alread e, i.e. moving
  {
    past_tense[strlen(past_tense) -1] = '\0';
    strcat(past_tense, "ing");
  }
  else { strcat(past_tense, "ing"); }

  _PF_COLOR(VERB_COLOR);   PF("%s", past_tense); _PF_COLOR(PF_WHITE);    
}
