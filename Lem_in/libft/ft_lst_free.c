/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:52:40 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:52:42 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free(t_list **list)
{
	t_list	*next;
	t_list	*current;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->content);
		current->content = NULL;
		free(current);
		current = next;
	}
	current = NULL;
}
