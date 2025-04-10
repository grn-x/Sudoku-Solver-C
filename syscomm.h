#ifndef SYSCOMM_H
#define SYSCOMM_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void open_in_default_editor(const char *filename);
char* get_current_directory();
#endif //SYSCOMM_H