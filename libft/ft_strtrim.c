/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:46:01 by mmohamma          #+#    #+#             */
/*   Updated: 2022/04/17 03:46:02 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trim_front(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i] && match(s1[i], set))
		i++;
	return (i);
}

static int	trim_end(char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1);
	i--;
	while (s1[i] && match(s1[i], set))
	{
		i--;
		if (i == 0)
			return (0);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		size;

	if (!s1)
		return (NULL);
	i = trim_front((char *)s1, (char *)set);
	j = trim_end((char *)s1, (char *)set);
	size = j - i + 1;
	if (j == 0)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (0);
	ptr[size] = '\0';
	while (size-- > 0)
		ptr[size] = s1[j--];
	return (ptr);
}
