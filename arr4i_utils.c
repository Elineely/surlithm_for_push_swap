/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr4i_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:32:25 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:44:33 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	sort4i(int *arr4i, int k)
{
	if (k == 0)
		return ;
	while (k > 0)
	{
		if (arr4i[k] == arr4i[k - 1])
		{
			print_error();
		}
		if (arr4i[k] < arr4i[k - 1])
		{
			swap_int(&arr4i[k], &arr4i[k - 1]);
		}
		k--;
	}
	return ;
}

int	store_and_sort(int *arr4i, char *str, int j, int *k)
{
	if (ft_strchr(&str[j], ' ') == 0)
		arr4i[*k] = ft_atoi(&str[j]);
	else
		arr4i[*k] = ft_atoi(ft_substr(str, j,
					(ft_strchr(&str[j], ' ') - (&str[j]))));
	sort4i(arr4i, (*k)++);
	if (ft_strchr(&str[j], ' ') == 0)
		return (0);
	return (*k);
}

int	*index_input(int argc, char **argv, unsigned int i_amount, int *arr4i)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 1;
	k = 0;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		while (argv[i][j] != '\0')
		{
			if (store_and_sort(arr4i, str, j, &k) == 0)
				break ;
			j = ft_strchr(&argv[i][j], ' ') - (&argv[i][0]);
			while (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (arr4i);
}
