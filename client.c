/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:35:19 by mmohamma          #+#    #+#             */
/*   Updated: 2022/05/30 00:02:38 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// remove below
#include <stdio.h>

// static void	binary_converter
// {
	
// }

static void	send_signal(int signum)
{
	printf("sent : %d\n", signum);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigact;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);

	sigact.sa_handler = send_signal;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	return (0);
}
