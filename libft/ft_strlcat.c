/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:26:23 by tperes            #+#    #+#             */
/*   Updated: 2021/12/08 09:11:51 by tperes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	len_src;

	i = 0;
	len = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len)
		return (dstsize + len_src);
	while (i < dstsize - len - 1 && src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (len + len_src);
}
