/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:22:28 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 11:25:27 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
	return ;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_full_of_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			i++;
			continue ;
		}
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]) == FALES)
			print_error();
		i++;
	}
	return (1);
}

unsigned int	check_input(int argc, char **argv)
{
	int				i;
	unsigned int	input_amount;

	if (argc < 2)
		exit(0);
	i = 1;
	input_amount = 0;
	while (i < argc)
	{
		if (count_chunk(argv[i], ' ') == EMPTY)
			print_error();
		is_full_of_digits(argv[i]);
		input_amount += count_chunk(argv[i], ' ');
		i++;
	}
	return (input_amount);
}
