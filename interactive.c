#include <stdio.h>
#include <stdlib.h>

void open_in_default_editor(const char *filename) {
#ifdef _WIN32
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "start \"\" \"%s\"", filename);
#elif __APPLE__
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "open \"%s\"", filename);
#else
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "xdg-open \"%s\"", filename);
#endif
    system(cmd);
}

void get_current_directory(const char *filename) {
    /*char cmd[256];
    snprintf(cmd, sizeof(cmd), "pwd > %s", filename);
    system(cmd);
    */
}