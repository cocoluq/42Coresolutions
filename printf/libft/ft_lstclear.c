/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:55:47 by luqli             #+#    #+#             */
/*   Updated: 2023/11/19 22:55:47 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*proceed;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		proceed = tmp -> next;
		(*del)(tmp -> content);
		free(tmp);
		tmp = proceed;
	}
	*lst = NULL;
}
