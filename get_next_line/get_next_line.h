/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:03:51 by mkinnear          #+#    #+#             */
/*   Updated: 2017/10/08 02:08:56 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 74

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int const fd, char **line);

#endif
