/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:41:30 by mmohamma          #+#    #+#             */
/*   Updated: 2022/05/30 20:02:44 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_int(long number)
{
	if (number > 2147483647)
		return (-1);
	if (number < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (sign *(str[i] - '0'));
		if (check_int(nb) < 1)
			return (check_int(nb));
		i++;
	}
	return ((int)nb);
}
