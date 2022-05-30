/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:43:04 by mmohamma          #+#    #+#             */
/*   Updated: 2022/04/17 03:43:05 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 2;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 1;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[len - i - 1] = -(n % 10) + '0';
		else
			str[len - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[len - 1] = '\0';
	return (str);
}
