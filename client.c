/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:37:12 by tperes            #+#    #+#             */
/*   Updated: 2022/04/08 23:47:24 by tperes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	send_signal(int pid, char *message)
{
	int	i;

	i = 7;
	while (*message)
	{
		while (i >= 0)
		{
			if (*message & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(500);
		}
		i = 7;
		message++;
	}
}

void	send_size(int pid, int size)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (size & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

void	handler1(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message bien transmis\n");
}

int	main(int ac, char **av)
{
	size_t				size;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = handler1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3 || av[2][0] == 0 || ft_atoi(av[1]) <= 0)
		write(1, "error\n", 6);
	else
	{
		size = ft_strlen(av[2]);
		send_size(ft_atoi(av[1]), size);
		send_signal(ft_atoi(av[1]), av[2]);
	}
}
