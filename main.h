#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#define MAX_ALIASES 10
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100
char alias_names[MAX_ALIASES][MAX_ALIAS_NAME_LENGTH];
char alias_values[MAX_ALIASES][MAX_ALIAS_VALUE_LENGTH];
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <math.h>
void print_aliases(void);
void print_alias(char *name);
void define_alias(char *name, char *value);
void handle_alias(char **argv);
int change_directory(char *path);
void free_tokens(char **tokens, int count);
extern char **environ;
char *_strtok(char *srcString, const char *delim);
int loop(char **env, char **av);
void _putchar(char str);
unsigned int is_delim(char c, const char *delim);
char **split(char *line);
int execute(char **argv, char **env, char **av);
char *find(char *command);
char *_getenv(const char *var);
int err_handle(int error_number, char *shell_name, int count,
		char *command, char *Argument, char *errorText);
ssize_t my_getline(char **pline, size_t *len, FILE *fp);
char *find_command(char *command, char *token);
int my_exit(char *arg);
void my_env(char **env);
void execute_command(char *command, char **argv, char **env, char **av);
int my_unsetenv(char *varaible);
int my_setenv(char *variable, char *value);
#endif
