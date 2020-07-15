/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 16:21:58 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void			free_graph(t_graph *graph)
{
	int	i;

	if (!graph)
		return ;
	if (graph->adj)
	{
		i = 0;
		while (i < graph->V)
		{
			free_list(graph->adj[i]);
			free(vertex_names[i]);
			i++;
		}
		free(graph->adj)
		free(graph->vertex_names);
	}
	free(graph);
}
