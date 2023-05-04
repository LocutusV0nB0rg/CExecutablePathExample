#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void remove_last_section(char* str, const char* delimiter) {
    char* last_delimiter = strrchr(str, *delimiter);
    if (last_delimiter != NULL) {
        *last_delimiter = '\0';
    }
}

char* getPathOfExecutable(char* buf) {
    ssize_t count = readlink( "/proc/self/exe", buf, PATH_MAX );
    buf[count] = '\0';
    remove_last_section(buf, "/");
    strcat(buf, "/");
    return buf;
}

int main() {
    char* buf = (char *) malloc(PATH_MAX + 1);
    getPathOfExecutable(buf);
    printf("Path: %s", buf);
}
