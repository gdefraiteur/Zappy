/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:47 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 17:37:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int	main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	srv_create(&e, get_opt(ac, av));
	main_loop(&e);
	return (0);
}
