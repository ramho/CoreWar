/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:18:51 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/10/16 17:43:16 by Ramata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

# ifdef __linux
#  define OPEN_MAX FOPEN_MAX
# endif

# define BUFF_SIZE 100

typedef	struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		s_gnl
{
	char			buff[BUFF_SIZE + 1];
	char			*rest[OPEN_MAX];
	int				ret;
	char			*ptr;
}					t_gnl;

typedef struct		s_flag
{
	int				hash;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				width;
	int				precision;
	int				l;
	int				h;
	int				upperl;
	char			*sign;
}					t_flag;

typedef	struct		s_base
{
	t_flag			flag;
	va_list			args;
	char			*con_str;
	char			**tab;
	int				len_fmt;
	int				type;
	int				len;
	int				tot_len;
	intmax_t		signed_nb;
	long double		signed_nb_f;
	size_t			count;
	int				malloc;
	int				one;
	long double		round_up;
	long double		deci_tmp;
}					t_base;

int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
char				*ft_itoa(long long n);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_memdel1(void *ap);
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_numlen(long long n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start,
						size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_n_free(char *s1, char *s2, int del);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_char(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
size_t				ft_strchri(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *str1, const char *str2,
						size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_countwords(char const *str, char c);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(long long value, int base, char c);
char				*ft_u_itoa_base(unsigned long long value, int base,
						char c);
int					ft_count_sym(char *str, char c);
int					ft_count_num(int value);
size_t				ft_pos_i(char *str, int c);

/*
**  ft_printf.c
*/
int					ft_printf(const char *fmt, ...);
int					parse_format(const char *format, int *i, t_base *all);
char				is_type(char c);
char				is_flag_char(char c);

/*
**  parse_flag.c
*/
t_flag				init_flag(t_flag flag);
int					no_conversion_char(char *str, t_base *all);
int					light_flags(t_base *all, char *str);
int					light_flags_bis(int *i, char *str, t_base *all);

/*
**  parse_flag_bis.c
*/
void				flag_zero(int *i, t_base *all, char *str);
void				width(int *i, t_base *all, char *str);
void				precision(int *i, t_base *all, char *str);
void				flag_l_h(int *i, t_base *all, char *str);

/*
**  start_conversion.c
*/
int					start_conversion(t_base *all);
void				init_function(int(*conversion[122])(t_base *all));

/*
**  convert_csp.c
*/
int					c_conversion(t_base *all);
int					p_conversion(t_base *all);
char				*p_conversion_bis(t_base *all, long int p, char *s);
int					s_conversion(t_base *all);

/*
**  convert_di.c
*/
int					di_conversion(t_base *all);
char				*di_conversion_thrice(t_base *all, char *s);
char				*di_conversion_twice(intmax_t nb, t_base *all, char *s);

/*
**  convert_oux.c
*/
int					u_conversion(t_base *all);
int					o_conversion(t_base *all);
char				*o_conversion_bis(uintmax_t nb, t_base *all, char *s);
int					x_conversion(t_base *all);
int					xupper_conversion(t_base *all);

/*
**  convert_modulo.c
*/
int					modulo_conversion(t_base *all);
int					modulo_conversion_bis(t_base *all);

/*
**  precision_flag.c
*/
char				*precision_s(t_base *all, char *s);
char				*precision_dioux(t_base *all, char *s);
char				*precision_dioux_bis(t_base *all, char *s);
char				*fill_zero(int size);

/*
**  width_n_final_flag.c
*/
int					ft_flag_width(t_base *all, char *s);
void				fill_width_space(t_base *all, char *str, int size);
void				final_conversion(t_base *all, char *s);

/*
**  length_modifiers_flag.c
*/
long double			check_l_lupper(t_base *all);
intmax_t			check_l_ll_h_hh(intmax_t nb, t_base *all);
uintmax_t			check_l_ll_h_hh_unsigned(uintmax_t nb, t_base *all);

/*
**  convert_f.c
*/
int					f_conversion(t_base *all);
void				round_float(t_base *all, long double *nb);
void				round_up(long double *nb, int decimal);
char				*get_deci_part(long double nb, t_base *all);
int					convert_f_bis(t_base *all, char *s, char *s_deci);

/*
**  convert_f.c
*/
int					free_1(t_base *all);
int					free_2(char *str);
char				*free_3(char *str);
int					free_4(char *s1, char *s2);

#endif
