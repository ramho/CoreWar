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

struct	s_asm
{
	char * file_name;
	struct header_s *header;
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
void get_name_comment(char *line, t_asm *champ);


/*
** free_error.c
*/

/*
**
*/

/*
**
*/



#endif
