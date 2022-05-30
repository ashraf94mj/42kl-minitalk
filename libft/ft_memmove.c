/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:44:29 by mmohamma          #+#    #+#             */
/*   Updated: 2022/04/17 03:44:31 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_p;
	unsigned char	*src_p;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	while (src > dest && i < n)
	{	
		dest_p[i] = src_p[i];
		i++;
	}
	while (dest > src && n > 0)
	{
		dest_p[n - 1] = src_p[n - 1];
		n--;
	}
	return (dest);
}
