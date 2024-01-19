
// int ADJECTIVE(int duplicate_count, ...)
// {
//   core_data_t* core_data = core_data_get();
//   
//   // get args
//   va_list list;
//   va_start(list, duplicate_count);
//   int* duplicates = NULL;
//   for (int i = 0; i < duplicate_count; ++i)
//   {
//     arrput(duplicates, va_arg(list, int));
//   }
//   va_end(list);
//   
//   // generate idx, check if duplicate
//   bool is_duplicate = false;
//   int idx = -1;
//   do
//   { 
//     idx = rand_int_range(0, core_data->adjectives_len);
//     is_duplicate = false;
//     for (int i = 0; i < duplicate_count; ++i)
//     {
//       if (duplicates[i] == idx) { is_duplicate = true; break; }
//     }
//   }
//   while (is_duplicate);
//   // while (idx == old_idx);
//   const char* word = core_data->adjectives[idx];
//   _PF_COLOR(ADJECTIVE_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  
// 
//   arrfree(duplicates);
// 
//   return idx;
// }

int NOUN(int duplicate_count, ...)
{
  core_data_t* core_data = core_data_get();
  
  // get args
  va_list list;
  va_start(list, duplicate_count);
  int* duplicates = NULL;
  for (int i = 0; i < duplicate_count; ++i)
  {
    arrput(duplicates, va_arg(list, int));
  }
  va_end(list);
  
  // generate idx, check if duplicate
  bool is_duplicate = false;
  int idx = -1;
  do
  { 
    idx = rand_int_range(0, core_data->nouns_len);
    is_duplicate = false;
    for (int i = 0; i < duplicate_count; ++i)
    {
      if (duplicates[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  // while (idx == old_idx);
  const char* word = core_data->nouns[idx];
  _PF_COLOR(NOUN_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  arrfree(duplicates);

  return idx;
}

int VERB(int duplicate_count, ...)
{
  core_data_t* core_data = core_data_get();
  
  // get args
  va_list list;
  va_start(list, duplicate_count);
  int* duplicates = NULL;
  for (int i = 0; i < duplicate_count; ++i)
  {
    arrput(duplicates, va_arg(list, int));
  }
  va_end(list);
  
  // generate idx, check if duplicate
  bool is_duplicate = false;
  int idx = -1;
  do
  { 
    idx = rand_int_range(0, core_data->verbs_len);
    is_duplicate = false;
    for (int i = 0; i < duplicate_count; ++i)
    {
      if (duplicates[i] == idx) { is_duplicate = true; break; }
    }
  }
  while (is_duplicate);
  // while (idx == old_idx);
  const char* word = core_data->verbs[idx];
  _PF_COLOR(VERB_COLOR);   PF("%s", word); _PF_COLOR(PF_WHITE);  

  arrfree(duplicates);

  return idx;
}


