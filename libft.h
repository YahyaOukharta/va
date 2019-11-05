/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:17:00 by youkhart          #+#    #+#             */
/*   Updated: 2019/11/02 20:55:58 by youkhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memset(void *ptr, int value, size_t n);
void				ft_bzero(void *ptr, int n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memmove(void *d, const void *s, size_t count);
void				*ft_memchr(const void *ptr, int c, size_t n);
int					ft_memcmp(const void *p1, const void *p2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *src);
void				*ft_calloc(size_t nitems, size_t size);
int					ft_atoi(const char *str);
char				*ft_itoa(int nbr);
char				*ft_utoa(unsigned int nbr);
char				*ft_itoa_base(long nbr, const char *base);
char				*ft_substr(const char *s, unsigned int i, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *str, const char *set);
char				**ft_split(const char *str, char c);
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
