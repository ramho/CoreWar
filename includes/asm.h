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
	int pos;
	char * file_name;
	char **file;
	struct header_s *header;
};

struct s_token
{
	int pos;
	int size_param;
	int8_t	encoded_byte; // size of 1 byte
	char *label;
	// struct s_op ;//opcode from global variable

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
void get_opcode(char *line, t_asm *champ, int row);
int parse_label(char *line, int i, int row);
int parse_op(char *line, int i, int op);
// void parse_param(char **tab);
void parse_param(int op, char **tab);
int check_param(char *param);

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
typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int			args_types_code; //
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
}				t_op;

static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = true,
		.args_types = {T_REG, 0, 0},
		.t_dir_size = 4,
	}
};

#endif
