/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:25:00 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:33:51 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# define START 0
# define MID 1
# define END 2
# define TRUE 1
# define FALSE 0
# define ANTCOUNT 1
# define ROOM 2
# define LINK 3
# define COMMENT 4
# define INVALID -1

typedef struct		s_ant
{
	int				id;
	int				arrived;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	int				cost;
	t_ant			**ants;
	struct s_room	**links;
	int				options_from;
	int				options_to;
	int				status;
}					t_room;

typedef struct		s_link
{
	char			*a;
	char			*b;
}					t_link;

void				ft_test_map();
int					get_type(char *line);
t_ant				**get_ants();
t_ant				*create_ant(int id);
t_room				*create_room(char *line);
t_room				**get_rooms();
int					room_count();
void				set_links(t_room **rooms, char **map);
void				set_link(t_room *room, t_room **rooms, char **map);
char				**get_link(char *line);
int					count_links(char *name, char **map);
int					index_of_room(t_room **rooms, char *name);
void				set_all_costs(t_room **rooms);
int					set_cost(t_room *room, t_room **rooms);
void				sort_rooms(t_room **rooms);
void				sort_links(t_room *room);
void				init_array(int *array, int size);
void				ft_freerooms(t_room **rooms);
void				calculate_options(t_room **rooms);
int					ft_validation(char **map);
void				ft_read_in_rooms(t_room **rooms, char **map);
void				ft_freeants(t_ant ***all_ants);
void				ft_displaymap(void);
void				load_ants(t_ant **ants, t_room **rooms);
void				melloc_ant_array(t_room *room, int ant_count);
int					move_ants(t_room **rooms, int len);
int					ant_to_room(t_ant *ant, t_room *room);
int					is_empty(t_room *room);
t_room				*get_available_room(t_room *current);
int					ants_in_room(t_room *room);
void				remove_ant(t_room *room, int index);
int					ant_moved(int *ants, int current_id, int len);
void				ft_init_ants_n_rooms(t_room ***r, t_ant ***a, char **map);
void				ft_setlink_helper(char *l, t_room **r, t_room *ro, int *i);
void				sort_equal_nodes(t_room *parent, int index);
void				init_links(t_room **links, int size);
int					contains_link (t_room *room, char *name);
int					move_from_start(t_room **rooms, int *i, int *ma, int len);
void				add_moved_ant(int *ants, int current_id, int len);
#endif
