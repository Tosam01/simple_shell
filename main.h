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

#define SHELL_STR "Simple_shell"

int simple_shell(void);
int find_file(char **arg, char *f, char *file_path, struct stat st);
int check_abs(char *c);
int find_env_var(char **arg, char **env, char *var);
int str_split(char **arg, char *av, char *delmt);

#endif
