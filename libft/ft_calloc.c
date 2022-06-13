/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:09:47 by tperes            #+#    #+#             */
/*   Updated: 2021/12/08 09:06:04 by tperes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	char	*tab;

	if (n == 0 || nmemb == 0)
	{
		n = 1;
		nmemb = 1;
	}
	tab = malloc((nmemb * n));
	if (tab != NULL)
		ft_bzero(tab, nmemb * n);
	return (tab);
}
