/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:42:48 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:42:52 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_elem(char **array, int i)
{
	free(array[i]);
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = NULL;
}

int		ft_2dcount(char **arr)
{
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

int		ft_2dcount_gen(void **arr)
{
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

void	ft_free2dsafe(void ***arr)
{
	int		i;
	void	**array;

	i = 0;
	array = *arr;
	if (array)
	{
		while (array[i])
		{
			ft_memdel(array + i);
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}

void	ft_remove_elem_gen(void **array, int i)
{
	free(array[i]);
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = NULL;
}
