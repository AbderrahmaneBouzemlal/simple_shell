#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char environ;
char **split(char *line);
int execute(char **argv, char **env);
char *find(char *command);
char *_getenv(const char *var);

#endif
