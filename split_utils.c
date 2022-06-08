/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:25:10 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 17:24:13 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strchr(const char *str, int c2find_first)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c2find_first)
			return ((char *)&str[i]);
		i++;
	}
	if (c2find_first == 0)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strrchr(const char *str, int c2find_last)
{
	int	slen;

	slen = ft_strlen(str) - 1;
	if (c2find_last == 0)
		return ((char *)&str[slen + 1]);
	while (slen >= 0)
	{
		if (str[slen] == c2find_last)
			return ((char *)&str[slen]);
		slen--;
	}
	return (0);
}

int	count_chunk(const char *str, char sep)
{
	int	count;
	int	i;
	int	slen;
	int	first_is_sep;
	int	last_is_sep;

	slen = (int)ft_strlen(str);
	if (slen == 0)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i + 1] != sep)
			count++;
		i++;
	}
	first_is_sep = (ft_strchr(str, sep) == str);
	last_is_sep = (ft_strrchr(str, sep) == str + (slen - 1));
	if (first_is_sep && last_is_sep)
		return (count - 1);
	if (!(first_is_sep) && !(last_is_sep))
		return (count + 1);
	return (count);
}
