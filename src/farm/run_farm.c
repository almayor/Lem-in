/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_farm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:57:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 23:39:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

static int		advance_farm(t_farm *farm, t_map *vertex_names)
{
	int		i;
	int		n_moved_ants;

	i = 0;
	n_moved_ants = 0;
	while (i < farm->n_ants)
	{
		if (farm->ants[i])
		{
			if (n_moved_ants > 0)
				ft_putchar(' ');
			ft_printf("L%i-%s",
				i + 1,
				key2val_map(vertex_names, farm->ants[i]->val]));
			farm->ants[i] = farm->ants[i]->next;
			n_moved_ants++;
		}
		i++;
	}
	ft_putchar('\n');
	return (n_advanced_ants);
}

static void		advance_to_finish_farm(t_farm *farm, t_map *vertex_names)
{
	while (advance_farm(farm, vertex_names) > 0)
		continue ;
}

int				run_farm(t_farm *farm, t_list **paths, int n_paths,
						t_map *vertex_names)
{
	int	n_active_ants;
	int	i;

	n_active_ants = 0;
	while (n_active_ants < farm->n_ants)
	{
		i = 0;
		while (i < n_paths)
		{
			farm->ants[n_active_ants++] = paths[i++];
			if (n_active_ants == farm->n_ants)
				break ;
		}
		advance_farm(farm, vertex_names);
	}
	advance_to_finish_farm(farm, vertex_names);
	return (errno > 0);
}
