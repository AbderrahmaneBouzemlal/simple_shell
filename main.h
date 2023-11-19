#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
int loop(char **env);
void _putchar(char str);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *srcString, const char *delim);
unsigned int is_delim(char c, const char *delim);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char **split(char *line);
int execute(char **argv, char **env);
char *find(char *command);
char *_getenv(const char *var);

#endif
