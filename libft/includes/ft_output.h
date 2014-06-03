/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 01:05:56 by garm              #+#    #+#             */
/*   Updated: 2014/06/03 17:26:51 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

# include <string.h>

/*
** stdout write functions
*/
int			ft_putchar(char c);
int			ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int num);
char		*ft_putnstr(const char *str, size_t n);
void		ft_fatal(char *str);
int			ft_error(char *str);

/*
** file descriptors write functions
*/
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char const *s, int fd);
char		*ft_putnstr_fd(char const *s, size_t n, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int num, int fd);

/*
** Formating
*/
int			ft_printf(const char *format, ...);
int			ft_fprintf(int fd, const char *format, ...);

#endif

