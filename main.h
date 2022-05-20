#ifndef CHECKER
#define CHECKER

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>



extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);


char *appender(char *path, char *cmd);
int checker(char **cmd, char *buffer);
void execute(char *cp, char **cmd);
void exit_cmd(char **cmd, char *line);
void free2(char **buf);
int _strcmp(char *s1, char *s2);
void signal_handler(int m);
int builtin_handlers(char **cmd, char *line);
int _strncmp(char *s1, char *s2, int n);
char *find_path(void);
void print_env(void);
void prompter(void);
char **tokenizer(char *line);
char *test_path(char **path, char *command);




int _strlen(char *s);

char *_strdup(char *s);
char *_strchr(char *s, char c);

/**
 * struct builtin - function that declares
 * built in command
 * @env: environment
 * @exit: exit
 */

struct builtin
{
	char *env;
	char *exit;
} builtin;

/*
 * struct info - function to show details
 * @final_exit: exit
 * @ln_count: unsigned count
 * @info: infomation
 */

struct info
{
	int final_exit;
	int ln_count;
} info;

/*
 * struct flags - function to process flags
 * @flags: flags
 */

struct flags
{
	bool interactive;
} flags;

#endif
