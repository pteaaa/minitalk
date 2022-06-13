/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:03:15 by tperes            #+#    #+#             */
/*   Updated: 2022/04/08 23:43:13 by tperes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_data
{
	int		size;
	int		recup;
	int		end;
	char	*str;
	int		pid;
}	t_data;

static t_data	g_d;

void	rec_size(int val)
{
	static int	i = 31;
	static int	len = 0;

	if (val == 1)
		len |= (1 << i);
	if (i == 0)
	{
		g_d.size = len;
		g_d.end = 1;
		i = 32;
		len = 0;
	}
	i--;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	g_d.pid = info->si_pid;
	if (g_d.recup < 32 && g_d.recup >= 0)
	{
		if (signum == SIGUSR1)
			rec_size(1);
		else
			rec_size(0);
	}
	else if (g_d.recup < g_d.size * 8 + 32)
	{
		if (signum == SIGUSR1)
			g_d.str[(g_d.recup - 32) / 8] |= (1 << (7 - (g_d.recup % 8)));
	}
	g_d.recup++;
}

void	message(void)
{
	if (g_d.end == 1)
	{
		g_d.str = ft_calloc(1, g_d.size + 1);
		if (!g_d.str)
			return ;
		g_d.end = 0;
	}
	if (g_d.recup == g_d.size * 8 + 32)
	{
		g_d.str[g_d.size] = '\0';
		ft_printf("%s\n", g_d.str);
		g_d.recup = 0;
		g_d.size = 0;
		free(g_d.str);
		kill(g_d.pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	g_d.size = 0;
	g_d.recup = 0;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		message();
	}
}
