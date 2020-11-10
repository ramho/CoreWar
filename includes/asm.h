#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // remove

typedef struct s_asm t_asm;

struct	s_asm
{
	char * file_name;
};

/*
** asm.c
*/
int	main(int ac, char **av);

/*
** valid_file.c
*/
void valid_file(t_asm *champ, char *file_name);

/*
** parse_tokens.c
*/






/*
**
*/


#endif
