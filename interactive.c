#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* get_current_directory() {
    char* result = NULL;
    FILE* pipe = NULL;

#ifdef _WIN32
    pipe = _popen("cd", "r");
#else
    pipe = popen("pwd", "r");
#endif

    if (pipe) {
        char buffer[1024];
        if (fgets(buffer, sizeof(buffer), pipe) != NULL) { // read
            //trailing newline removal
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
                buffer[len-1] = '\0';
            }

            result = (char*)malloc(len + 1);
            if (result) {
                strcpy(result, buffer);
            }
        }

#ifdef _WIN32
        _pclose(pipe);
#else
        pclose(pipe);
#endif
    }

    return result;
}

/*int main() { //test functionality
    char* current_dir = get_current_directory();
    if (current_dir) {
        printf("Current directory: %s\n", current_dir);
        free(current_dir);
    } else {
        printf("Failed to get current directory.\n");
    }


    open_in_default_editor("approve.txt");

    return 0;
}*/