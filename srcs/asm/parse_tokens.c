#include "../../includes/asm.h"

// Syntax error at token
void get_file(char *file, t_asm *champ)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		if (line[0] == '.')
			get_name_comment(line, champ);
		free(line);
	}
}

void get_name_comment(char *line, t_asm *champ)
{
	char **tab;

	champ->header = ft_memalloc(sizeof(header_t));
	if (line[1] == 'n')
	{
		tab = ft_strsplit(line, '"');
		if (ft_strlen(tab[1]) <= PROG_NAME_LENGTH)
			ft_memcpy(champ->header->prog_name, tab[1], ft_strlen(tab[1]));
		else
		{
			ft_printf("Champion name too long (Max length 128)\n");
			//free champ et header
			exit(-1);
		}
	}
	else if (line[1] == 'c')
	{
		tab = ft_strsplit(line, '"');
		if (ft_strlen(tab[1]) <= COMMENT_LENGTH)
			ft_memcpy(champ->header->comment, tab[1], ft_strlen(tab[1]));
		else
		{
			ft_printf("Champion comment too long (Max length 2048)\n");
				//free champ et header
			exit(-1);
		}
	}
}
void parse_label()
{}

void parse_op()
{}

void parse_param()
{}
