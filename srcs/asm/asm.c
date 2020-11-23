#include "../../includes/asm.h"

//check for the entension '.s'

/*void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		printf("[%d]\n", data[pos + size - 1]);
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}*/



t_asm *check_arg(int ac, t_asm *champ)
{
	if (ac < 2)
	{
		ft_printf("Usage: ./asm [-*****] <sourcefile.s>\n");
		return (0);
	}
	if(!(champ = ft_memalloc(sizeof(t_asm))))
		return (0);
	return (champ);
}

int	main(int ac, char **av)
{
	t_asm *champ;
	char *line;
	int fd;

	if (!(champ = check_arg(ac, champ)))
		return (-1);
	if (valid_file(champ,  av[ac - 1]))
		get_file(av[ac - 1], champ);
	return (0);
}