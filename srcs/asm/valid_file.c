#include "../../includes/asm.h"

// if no file " Can't read source file %s"

void valid_file(t_asm *champ, char *file_name)
{
	int len;

	len = ft_strlen(file_name);
	if (file_name[len - 2] == '.' && file_name[len - 1] == 's')
	{
		printf("IN\n");
		if (!(champ->file_name = ft_strsub(file_name, 0, len - 2)))
			return ;
		open_file(file_name);
	}
	else
	{
		printf("Can't read source file %s\n", file_name);
	}
}

void open_file(char *file_name)
{
	int fd;
	char *line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	while ((get_next_line(fd, &line )) > 0)
	{
		printf("line = %s\n", line);
	}
}
