/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:51:29 by tperes            #+#    #+#             */
/*   Updated: 2021/12/12 09:39:06 by tperes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	new = malloc(sizeof(char) * (end - start) + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (start <= end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
