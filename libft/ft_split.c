/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:44:51 by mmohamma          #+#    #+#             */
/*   Updated: 2022/04/17 03:44:52 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}

static char	*dup_word(char const *s, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (s[i] && i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	word = 0;
	matrix = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!matrix)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i - j > 0)
			matrix[word++] = dup_word(&s[j], i - j);
	}
	matrix[word] = NULL;
	return (matrix);
}
