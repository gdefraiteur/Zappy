/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 00:31:30 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:13:14 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

/*
** Char functions
*/
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_iswhitespace(int c);

#endif

