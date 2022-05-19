#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SHELL_STR "cisfun#: "

int simple_shell(void);
int find_file(char **arg, char *f);
int check_abs(char *c);
int find_env_var(char **arg, char **env, char *var);
int str_split(char **arg, char *av, char *delmt, char *delmt2);
int shell(char **argv, char **env);
int execute(char *cmd, char **arg);
int check_next(char **arg, int prev);
#endif
