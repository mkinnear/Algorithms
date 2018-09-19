/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:55:50 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:55:51 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	size_t	size;

	size = content_size;
	link = (t_list*)malloc(sizeof(t_list));
	if (link)
	{
		if (content != NULL)
		{
			if (!(link->content = ft_memalloc(size + 1)))
				return (NULL);
			link->content = ft_memcpy(link->content, (void*)content, size);
			link->content_size = content_size;
		}
		else
		{
			link->content_size = 0;
			link->content = NULL;
		}
		link->next = NULL;
	}
	return (link);
}
