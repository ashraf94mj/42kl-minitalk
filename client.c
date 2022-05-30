/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:35:19 by mmohamma          #+#    #+#             */
/*   Updated: 2022/05/30 17:42:09 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			bit++;
		}
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

static void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Message Successfully Sent\n", 26);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigact;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("Invalid Arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sigact.sa_handler = signal_handler;
	sigact.sa_flags = 0;
	sigaction(SIGUSR1, &sigact, NULL);
	send_bits(pid, argv[2]);
	return (0);
}
