/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:19:57 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/21 14:43:30 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_mstr
{
	char				*str;
	int					flag;
	int					diff;
	char				*buff;
}						t_mstr;

size_t					ft_strlen(const char *s1);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *s, int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,\
									int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *big, const char *little);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,\
									size_t len);
int						ft_atoi(const char *str);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
char					*ft_strcut(char *str, char c);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)\
									(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,\
									size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)\
										(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstaddend(t_list *alst, t_list *lst);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_swap(int *a, int *b);
int						ft_sqrt(int nb);
int						*ft_range(int min, int max);
char					**ft_whitespace(char const *s);
int						get_next_line(const int fd, char **line);
char					*ft_strjoin_free(char **s1, char **s2);
char					*ft_strjoin_free_one(char **s1, char *s2);
void					lst_add(t_list *lst, t_list **start);
size_t					ft_count_lst(t_list	*lst);
int						ft_isnumber(char *str);
char					*ft_wordtab_to_str(char **wordtab);
size_t					ft_tab_size(char **tab);
int						ft_isalnumword(char *str);
char					*ft_str_epur(char *str);

#endif
