/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 00:59:39 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:15:17 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# define MALLOC 0
# define REALLOC 1
# define FREE 2
# define FREEALL 3

# include <string.h>
# include <stdarg.h>

/*
** t_int = tiny_int;
*/
typedef char	t_int;

typedef struct	s_reg
{
	struct s_reg	*next;
	void			*addr;
}				t_reg;

/*
** Memory functions
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_remalloc(void *addr, size_t oldsize, size_t newsize);

/*
** Secure memory functions
*/
t_int			ft_smem(int flag, void **addr, ...);
void			*ft_smalloc(size_t size);
t_int			ft_sfree(void *addr);
t_int			ft_sfreeall(void);

#endif

