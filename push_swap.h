/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:57:32 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 13:32:35 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define TRUE 1
# define FALES 0
# define EMPTY 0

/*   check_utils.c    */
void			ft_putstr_fd(char *str, int fd);
int				ft_isdigit(int c);
void			print_error(void);
int				is_full_of_digits(char *str);
unsigned int	check_input(int argc, char **argv);

/*   split_utils.c     */
char			*ft_strchr(const char *str, int c2find_first);
char			*ft_strrchr(const char *str, int c2find_last);
int				count_chunk(const char *str, char sep);
size_t			ft_strlen(const char *str);

/*   atoi_utils.c    */
int				ft_isspace(char c);
int				ft_atoi(const char *str);

/*   substr_utils.c    */
char			*ft_substr(char const *s, unsigned int start, size_t len_no0);

/*   arr4i_utils.c    */
void			swap_int(int *a, int *b);
void			sort4i(int *arr4i, int k);
int				store_and_sort(int *arr4i, char *str, int j, int *k);
int				*index_input(int argc, char **argv, \
				unsigned int i_amount, int *arr4i);

#endif