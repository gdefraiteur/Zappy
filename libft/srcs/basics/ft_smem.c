/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:51:48 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:27:24 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_standard_helpers.h"
#include "ft_memory.h"

static void		ft_reg_init(t_reg *reg)
{
	static t_int	first_time = 1;

	if (first_time)
	{
		reg->addr = NULL;
		reg->next = NULL;
	}
	first_time = 0;
}

static t_int	ft_reg_malloc(t_reg *reg, void **addr, size_t size)
{
	t_reg	*regelem;

	if ((*addr = ft_memalloc(size)) == NULL)
		return (-1);
	if ((regelem = (t_reg *)ft_memalloc(sizeof(t_reg))) == NULL)
		return (-1);
	if (addr && *addr)
	{
		regelem->addr = *addr;
		regelem->next = reg->next;
		reg->next = regelem;
		return (0);
	}
	return (-1);
}

static t_int	ft_reg_free(t_reg *reg, void **addr)
{
	t_reg	*cur;
	t_reg	*tmp;

	cur = reg;
	tmp = reg;
	while (cur && cur->next)
	{
		if (cur->next->addr == *addr)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			tmp->next = NULL;
			free(*addr);
			free((void *)tmp);
			return (0);
		}
		cur = cur->next;
	}
	return (-1);
}

static t_int	ft_reg_freeall(t_reg *reg)
{
	int		error;

	error = 0;
	while (reg->next)
	{
		if (ft_reg_free(reg, &(reg->next->addr)) == -1)
			error = -1;
	}
	return (error);
}

t_int			ft_smem(int flag, void **addr, ...)
{
	static t_reg	reg;
	size_t			size;
	va_list			ap;

	va_start(ap, addr);
	ft_reg_init(&reg);
	if (flag == MALLOC)
	{
		size = va_arg(ap, size_t);
		va_end(ap);
		return (ft_reg_malloc(&reg, addr, size));
	}
	if (flag == FREE)
		return (ft_reg_free(&reg, addr));
	if (flag == FREEALL)
		return (ft_reg_freeall(&reg));
	return (0);
}
