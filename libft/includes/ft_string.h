/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 00:45:59 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:19:44 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <string.h>

/*
** String Functions
*/
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_strisnum(char *str);
size_t		ft_strlen(const char *str);
size_t		ft_strlenc(const char *str, char c);

char		*ft_strdup(const char *src);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);

char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);

void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrev(char const *str);

char		*ft_strtrim(char const *s);
char		*ft_strtrimc(char const *str, char c);

char		*ft_strdelmultic(char const *str, char c);
int			ft_strcountc(char const *str, char c);
int			ft_findc(const char *str, char c);
char		ft_strpickchar(char *str, int index);
char		*ft_strsubc(char *str, char oldc, char newc);

#endif

