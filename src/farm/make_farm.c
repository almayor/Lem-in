/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:56:48 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 16:06:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

t_farm	*make_farm(int n_ants)
{
	t_farm	*farm;

	if (!(farm = ft_calloc(sizeof(t_farm), 1)) ||
		!(farm->ants = ft_calloc(sizeof(t_list *)), n_ants))
	{
		errno = ENOMEM;
		free_farm(farm);
		return (NULL);
	}
	farm->n_ants = n_ants;
	return (farm);
}
