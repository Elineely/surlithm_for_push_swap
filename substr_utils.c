/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:22:53 by surlee            #+#    #+#             */
/*   Updated: 2022/04/10 19:40:18 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlcat(char *dst, const char *src, size_t resultsize_i_0)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	result;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	result = dlen + slen;
	if (resultsize_i_0 <= dlen)
		return (resultsize_i_0 + slen);
	while (dlen + 1 < resultsize_i_0 && src[i] != 0)
	{
		dst[dlen++] = src[i++];
	}
	dst[dlen] = '\0';
	return (result);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t resultsize_i_0)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (dst == src || resultsize_i_0 == 0)
		return (slen);
	while (i + 1 < resultsize_i_0 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len_no0)
{
	char			*substr;
	unsigned int	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		len_no0 = 0;
	substr = malloc(sizeof(char) * (len_no0 + 1));
	if (substr == NULL)
		return (0);
	if (start >= slen)
	{
		ft_strlcpy(substr, "", 1);
		return (substr);
	}
	ft_strlcpy(substr, s + start, len_no0 + 1);
	return (substr);
}
