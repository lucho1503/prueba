#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

int main(int argc, char **argv, char **env);
void INThandler(int sig);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
unsigned int largo_del_comando(char *s);
char **_strtok(char *str);
unsigned int count_dir(char *path);
char **store_environ(char *com, char **env);
char *_getenv(const char *name, char **environ);
void eof(char *ptr);
char *_strncpycmd(char *dest, char *src, char* com, int n, int c);
char *_strncpyconst(char *dest, const char *src, int n);
void com_null(char* buf);
void exit_out(char *buf, char **com);
void env_out(char *buf, char** com, char **env);
void error_fork();
void error_msg(char **argv, char *com, int i);
int _puterror(char c);
void parent_free(char *buf, char **com);
void _path(char **com, char *buf, char **env, char **argv, int conteo);
void print_env(char **env);
void free_all(char **double_ptr);
unsigned int _strlen_const(const char *name);

