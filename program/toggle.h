#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Helper function for toggle_definition(...). Returns the size of a char * till the first \0.
int size_of_string(char * string, const int max_size);

//Helper function for toggle_definition(...). Find the place of find_string. Returns 0 on success.
//fp will be at the start of the line of this definition.
int find_definition(FILE *fp, const char * find_string);

//Returns 0 on success. Error handling sucks though.
int toggle_definition(const char *def_file_name, const char * definition);
