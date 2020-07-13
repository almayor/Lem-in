/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_edkarp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:01:25 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 21:36:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edmonds-karp.h"

t_edkarp	*make_edkarp(const t_graph *graph, int source, int sink)
{
	t_edkarp	*edkarp;

	if (!graph || source == sink ||
		source < 0 || source >= graph->V ||
		sink < 0 || sink >= graph-V)
	{
		errno = EINVAL;
		return (NULL);
	}
	if (!(edkarp = ft_calloc(sizeof(t_edkarp), 1)) ||
		!(edkarp->marked = ft_calloc(sizeof(int), graph->V)) ||
		!(edkarp->edge_to = ft_calloc(sizeof(int), graph->V)) ||
		!(edkarp->dist_to = ft_calloc(sizeof(int), graph->V)))
	{
		errno = ENOMEM;
		free_edkarp(edkarp);
		return (NULL);
	}
	return (edkarp);
}
