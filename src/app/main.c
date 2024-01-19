#include "app/file_io.h"
#include "app/core_data.h"

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

int main(int argc, char** argv)
{
  core_data_t* core_data = core_data_get();

  P("hello, world");

	return 0;
}

