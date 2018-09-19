/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:26:14 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 13:38:59 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = (t_string)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
