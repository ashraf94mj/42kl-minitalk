/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:35:16 by mmohamma          #+#    #+#             */
/*   Updated: 2022/05/29 21:43:21 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// remove below
#include <stdio.h>

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	
	
	if (signum == SIGUSR1)
		printf("In signal handler function %d\n", signum);
	else
		printf("In signal handler function %d\n", signum);
	
}

//testing simple signal handler (remmebr remove)
// static void	signal_handler2(int signum)
// {
// 	printf("In signal handler function = %d\n", signum);
// }

int	main(void)
{
	struct sigaction	sigact;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	
	// test with sa.handler (remove after test)
	// sigact.sa_handler = signal_handler2;
	// sigact.sa_flags = 0;
	// sigaction(SIGUSR1, &sigact, NULL);
	// sigaction(SIGUSR2, &sigact, NULL);

	sigact.sa_sigaction = &signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	
	//artificial raise signal (remove after test)
	kill(getpid(), SIGUSR1);
	raise(SIGUSR2);
	
	while (1)
		pause();
	return (0);
}
