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
// typedef struct s_label t_label;

struct	s_asm
{
	int i;
	int row;
	int pos; //  number of bytes
	char *line;
	char *file_name;

	char *program;
	char *code;
	// char **file;
	struct header_s *header;
	struct	s_label *head;
	struct s_token *first;
	struct s_token *new_token;
};

struct s_token
{
	uint32_t pos; // [*] position in byte to use if label
	int op_code; // [*] opcode value to find in t_op
	int8_t	encoded_byte; // [ ] size of 1 byte only if t_op->args_type_code true
	char *label; // [*] name of label so can find it in label chained list
	char *param[3]; // [ ] poir sauvegarder les valeur
	int8_t param_type[3]; // type of param
	char *line; // [*]so can check index of error label later on using strstri
	int column; // [*] have index for error mgmt // can keep in in asm
	struct s_token *next;
};

struct s_param
{
		int type;
		int size;
		int hex;
		char *label;
};

typedef struct s_label
{
	char *name;
	int pos;
	int flag;
	struct s_label *next;
} t_label ;


/*
** asm.c
*/
int	main(int ac, char **av);
t_asm *check_arg(int ac, t_asm *champ);

/*
** file.c
*/
int		valid_file(t_asm *champ, char *file_name);
void	get_file(char *file, t_asm *champ);
int		create_cor_file(t_asm *champ);

/*
** parse_tokens.c
*/
void	parse_token(char *line, t_asm *champ);

/*
** free_error.c
*/
void	invalid_header(t_asm *champ, int error);
void	file_error(t_asm *champ, char *file_name, int error);
void	malloc_error(t_asm *champ, char *file);
void	free_chained_label(t_asm *champ);

/*
** parse_header.c
*/
void	get_name_comment(char *line, t_asm *champ, int len);
void	check_comment(int len, char *str, char *line, t_asm *champ);
char	*str_to_char(char *str, char c);

/*
** parse_op.c
*/
int		parse_op(char *ret, char *line, int i, int op, t_asm *champ, int column);
void	check_op(char *name, char *line, int size_op, t_asm *champ, int column);
void	calc_new_pos(t_token *token, t_asm *champ);

/*
** parse_param.c
*/
void	parse_param(int op, char **tab, t_asm *champ);
int		check_param(char *param, t_asm *champ, int param_i);

/*
** parse_param_utils.c
*/
int		check_dir(char *param, int param_i, t_asm *champ);
int		check_ind(char *param, int param_i, t_asm *champ);
int		check_reg(char *param, int param_i, t_asm *champ);

/*
** parse_label.c
*/
void	check_label_error(char *line, int index, int row);
int		parse_label(char *line, int i, int row, t_asm *champ);

/*
** op_chained_list.c
*/
void	add_op_link(t_token *new, t_asm *champ);
t_token	*init_op_link(t_token *new, t_token *first);

/*
** label_chained_list.c
*/
void 	add_label_link(t_label *new, t_asm *champ);
t_label	*init_label_link(t_label *new, t_label *head);

/*
** init.c
*/
void	init_asm(t_asm *champ);
void	init_label_struct(t_asm *champ);
void	init_token_struct(t_asm *champ);



/*
** encode.c
*/
void	encode(t_asm *champ, int fd);
void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size);
uint8_t	code_encoded_byte(t_token *token, int op);
int code_param(char *code, t_token *token);

/*
** transfer_to_str.c
*/
void	transfer_cmd_to_str(t_asm *champ, int fd);
static int32_t	ft_llongmax(unsigned long long int nb, int sign);// a voir si je garde, testing
int32_t			ft_atoi32(const char *str); // a voir si je garde, testing

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
	int			args_types_code; // encoded byte
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
