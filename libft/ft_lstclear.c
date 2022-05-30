/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:43:50 by mmohamma          #+#    #+#             */
/*   Updated: 2022/04/17 03:43:51 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*content;
	t_list	*next;

	content = *lst;
	if (!content)
		return ;
	while (content)
	{
		next = content->next;
		ft_lstdelone(content, del);
		content = next;
	}
	*lst = NULL;
}
