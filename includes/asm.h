#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <sys/stat.h>
# include <stdio.h> // remove

typedef struct s_asm t_asm;
typedef struct s_token t_token;
typedef struct s_param t_param;

struct	s_asm
{
	char * file_name;
	struct header_s *header;
};

struct s_token
{
	int pos;
	char *label;

};

struct s_param
{
		int type;
		int size;
		int hex;
};


/*
** asm.c
*/
int	main(int ac, char **av);
t_asm *check_arg(int ac, t_asm *champ);

/*
** valid_file.c
*/
int valid_file(t_asm *champ, char *file_name);

/*
** parse_tokens.c
*/
void get_file(char *file, t_asm *champ);

/*
** free_error.c
*/
void invalid_header(t_asm *champ, int error);
void file_error(t_asm *champ, char *file_name, int error);
void malloc_error(t_asm *champ, char *file);

/*
** parse_header.c
*/
void get_name_comment(char *line, t_asm *champ, int row, int len);
void check_comment(int len, int row, char *str, char *line, t_asm *champ);
char *str_to_char(char *str, char c);



/*
**
*/

/*
**
*/

/*
**
*/

/*
**
*/

/*
**
*/

#endif
