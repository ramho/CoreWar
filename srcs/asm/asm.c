#include "../../includes/asm.h"

//check for the entension '.s'

void valid_file(t_asm *champ, char *file_name);

int	main(int ac, char **av)
{
	t_asm *champ;

	if (ac < 2)
	{
		printf("Usage: ./asm [-*****] <sourcefile.s>\n");
		return (-1);
	}
	if(!(champ = ft_memalloc(sizeof(t_asm))))
		return (-1);
	valid_file(champ, av[ac - 1]);
	printf("I'm back\n");
	return (0);
}
