#include "main.h"
#define MAX_ALIASES 10
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100
struct Alias {
    char name[MAX_ALIAS_NAME_LENGTH];
    char value[MAX_ALIAS_VALUE_LENGTH];
};
struct Alias aliases[MAX_ALIASES];
int alias_count = 0;
void print_aliases() {
    	int i;
	for (i = 0; i < alias_count; i++) {
        	printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

void print_alias(char *name) {
    	int i;
	for (i = 0; i < alias_count; i++) {
        	if (strcmp(aliases[i].name, name) == 0) {
            	printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            	return;
        }
    }
}

void define_alias(char *name, char *value) {
    	int i;
	for (i = 0; i < alias_count; i++) {
        	if (strcmp(aliases[i].name, name) == 0) {
            		strcpy(aliases[i].value, value);
            		return;
        }
    }

    if (alias_count < MAX_ALIASES) {
        strcpy(aliases[alias_count].name, name);
        strcpy(aliases[alias_count].value, value);
        alias_count++;
    } else {
        fprintf(stderr, "alias: Too many aliases\n");
    }
}

void handle_alias(char **argv) {
    if (argv[1] == NULL) {
        print_aliases();
    } else if (argv[2] == NULL) {
        print_alias(argv[1]);
    } else {
        int i = 1;
        while (argv[i] != NULL) {
            char *name = strtok(argv[i], "=");
            char *value = strtok(NULL, "=");

            if (name != NULL && value != NULL) {
                define_alias(name, value);
            } else {
                fprintf(stderr, "alias: Invalid syntax\n");
                return;
            }

            i++;
        }
    }
}
