/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:24 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:31:26 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 32

typedef char*		t_string;
typedef const char*	t_const;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_test_alpha(t_string s);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(t_string dst, const t_string src);
char				*ft_strncpy(t_string dst, const t_string src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(t_string s1, const t_string s2);
char				*ft_strncat(t_string s1, const t_string s2, size_t n);
size_t				ft_strlcat(t_string dst, t_string src, size_t size);
char				*ft_strchr(const t_string s, int c);
char				*ft_strrchr(const t_string str, int ch);
char				*ft_strstr(const char *big, const char *little);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
char				*ft_strnstr(const char *big, const char *litle, size_t len);
int					ft_isprint(int c);
int					ft_isalnum(int ch);
int					ft_isalpha(int c);
int					ft_isalldigit(char *s);
void				ft_strdel(t_string *s);
int					ft_atoi(const t_string str);
void				*ft_memset(void *dest, int ch, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(t_string s);
void				ft_putstr(const t_string s);
void				ft_putchar(char c);
char				*ft_strjoin(const t_string s1, const t_string s2);
char				*ft_strjoinf(const t_string *s1, const t_string s2);
char				*ft_strsub(const char *s, unsigned int start, size_t n);
int					ft_strequ(const t_string s1, const t_string s2);
int					ft_strnequ(const t_string s1, const t_string s2, size_t n);
void				ft_striter(t_string s, void (*f)(char *));
void				ft_striteri(t_string s, void (*f)(unsigned int, char *));
char				*ft_strmap(const t_string s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);
t_string			*ft_strsplit(t_string s, char c);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const t_string s);
void				ft_putstr_fd(const t_string s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_check_size(char *s, size_t start, size_t end);
int					ft_int_max_min(char *s, char sign, size_t st, size_t e);
void				ft_lstadd_last(t_list **alst, t_list *link);
int					ft_lst_count(t_list *list);
int					ft_lst_contains(t_list *list, void *content);
void				ft_lst_print(t_list *lst);
void				ft_lstadd_last_d(t_list **alst, void *cont, size_t size);
void				ft_lstadd_first_d(t_list **alst, void *cont, size_t size);
void				ft_lst_free(t_list **list);
t_string			ft_lst_to_string(t_list **letters);
t_string			*ft_lst_to_2dstring(t_list **list);
void				ft_lst_free(t_list **list);
t_string			*ft_split(t_string s);
int					ft_isspace(char c);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new_node);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd_last(t_list **alst, t_list *link);
void				ft_del(void *content, size_t content_size);
int					ft_2dcount(char **arr);
int					ft_2dcount_gen(void **arr);
void				ft_2dfree(void **array);
void				ft_free2dsafe(void ***arr);
void				ft_remove_elem(char **array, int i);
int					get_next_line(const int fd, char **line);
#endif
