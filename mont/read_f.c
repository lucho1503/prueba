#include "monty.h"

void find_fun(char *opcode, char *value, int n_line, int format)
{
        int i, flag;

        
        instruction_t func_list[] = {
                {"push", push_stack},
                {"pall", pall_stack},
                {"pint", pint_stack},
                {"pop", pop_stack},
                {NULL, NULL}
        };

        if (opcode[0] == '#')
                return;
        for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, func_list[i].opcode) == 0)
                {
                        get_f(func_list[i].f, opcode, value, n_line, format);
                        flag = 0;
                }
        }
        if (flag == 1)
        {
                printf("L%d: unknown instruction %s\n", n_line, opcode);
                exit(EXIT_FAILURE);
	}
}

int interp_line(char *linep, int n_line, int format)
{
        char *delim, *opcode, *value;

        if (linep == NULL)
        {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        delim = "\n ";
        opcode = strtok(linep, delim);

        if (opcode == NULL)
                return (format);
        value = strtok(NULL, delim);

        if (strcmp(opcode, "queue") == 0)
                return (1);
        else if (strcmp(opcode, "stack") == 0)
                return (0);

        find_fun(opcode, value, n_line, format);
	return (format);
}

void read_f(FILE *fd)
{
        int n_line, format;
        char *linep;
        size_t n;

        linep = NULL;
        n = 0;
        format = 0;

        if (fd == NULL)
        {
                printf("Error: Can't open file %s\n", (char *)fd);
                exit(EXIT_FAILURE);
        }
        for (n_line = 1; getline(&linep, &n, fd) != EOF; n_line++)
        {
                format = interp_line(linep, n_line, format);
        }
        free(linep);
}

void open_f(char *f_name)
{
	int file_exists;
        FILE *fd;

        if (f_name == NULL)
	{
                printf("Error: Can't open file %s", f_name);
		exit(EXIT_FAILURE);
	}
        file_exists = access(f_name, R_OK);
        if (file_exists == -1)
	{
                printf("Error: Can't open file %s", f_name);
		exit(EXIT_FAILURE);
	}
	fd = fopen(f_name, "r");
        if (fd == NULL)
	{
                printf("Error: Can't open file %s", f_name);
		exit(EXIT_FAILURE);
	}
	read_f(fd);
	fclose(fd);
}

