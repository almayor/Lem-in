/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bellman_ford.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:49:47 by user              #+#    #+#             */
/*   Updated: 2020/10/09 20:40:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <limits.h>
#include <assert.h>

static void	relax_edges(t_graph *graph)
{
	int		v;
	int		w;
	t_link	*link;

	v = 0;
	while (v < graph->nnodes)
	{
		link = graph->nodes[v]->edges->head;
		while (link)
		{
			w = link->content;
			graph_relax_edge(graph, v, w);
			link = link->next;
		}
		v++;
	}
}

int 		graph_bellman_ford(t_graph *graph)
{
	int	i;

	graph_reset(graph);
	i = 0;
	while (i < graph->nnodes - 1)
	{
		relax_edges(graph);
		i++;
	}
	return (graph->nodes[graph->end]->edge_in >= 0);
}
