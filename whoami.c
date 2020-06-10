#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

typedef int (*org_puts)(const char *str);

int puts(const char *str) {

    char new_str[10];
    org_puts original_puts;
    original_puts = (org_puts) dlsym(RTLD_NEXT, "puts");


    if(strcmp(str, "uju") == 0)
    {
        strcpy(new_str, "root");
    }

    return original_puts(new_str);
}

s