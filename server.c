/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:35:16 by mmohamma          #+#    #+#             */
/*   Updated: 2022/05/30 17:06:05 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		count = 0;
	static char		c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c += 1 << count;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigact.sa_sigaction = signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
