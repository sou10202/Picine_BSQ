/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:55:38 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:32:19 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX(i, j) (((i) > (j)) ? (i) : (j))

char		**ft_split(char *str, char *charset);
int			check_charset(char str, char *charset);
int			count_words(char *str, char *charset);
int			check_div_len(char *str, char *charset, int start);
char		*cpy(char *dest, char *src, unsigned int n, int j);
char		*read_file(int filen, char **argv);
void		print_ans(char **ans);
int			find_min(int a, int b, int c);
void		print_error(void);
int			row(char *buff);
char		*line1check(char *buff);
int			min(int a, int b, int c);
int			cn_memori_size(char *filename);
char		**makefield(int filen, char **argv);
char		*read_file(int filen, char **argv);
int			cn_memori_size(char *filename);
char		*line1check(char *buff);
int			set_char(char *c, char *buff, int i);
int			set_nb(char *buffer, int i, int flag);
int			com_nb(int a, int b);
int			count_col_size(char *buffer);
char		*file_to_buff(char *buff, int filesize, int fd);
int			error_check_all(char *buffer);
int			check_all_moji(char *buffer);
int			ft_str_is_printable_re(char *str);
int			check_row_num(char *buffer);
int			check_col_num(char *buffer, int col_size);
int			ft_strlen(char *str);
int			skip_line(char *buffer, int i);

typedef struct s_xy
{
	int		r;
	int		c;
}			t_xy;

typedef struct s_buff
{
	int		i;
	int		size;
	int		fd;
	char	*buffer;
}			t_buff;

typedef struct s_main
{
	int		i;
	char	*fc;
	char	*buf;
}			t_main;

t_xy		search_ans(t_xy coord, char **field, char *fieldchar);
int			to_print_ob(t_xy cnt, t_xy ans, int max_width);
void		printans(char *fieldchar, char **field, int i, char **argv);
int			**w_mall(t_xy coord);
int			**to_fill_0(t_xy coord, char **field, char *fieldchar);
int			getlargest(t_xy coord, char **field, char *fieldchar);
int			**getlargestsquare(t_xy coord, char **field, char *fieldchar);
t_xy		fillrowcol(int i, char **argv);
int			check_min(int **w, t_xy cnt);

#endif
