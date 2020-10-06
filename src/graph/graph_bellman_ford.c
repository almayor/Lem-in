/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bellman_ford.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:49:47 by user              #+#    #+#             */
/*   Updated: 2020/10/06 18:54:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <limits.h>

static void	relax_edges(const t_graph *graph, int *edge_to, int *cost_to)
{
	int			v;
	int			w;
	int			c;
	t_edge		*edge;

	v = 0;
	while (v < graph->nverti)
	{
		edge = graph->nodes[v]->edges;
		while (edge)
		{
			w = edge->to;
			c = edge->cost;
			if (cost_to[w] > cost_to[v] + c)
			{
				edge_to[w] = v;
				cost_to[w] = cost_to[v] + c;
			}
			edge = edge->next;
		}
		v++;
	}
}

static void	initialize(const t_graph *graph, int *edge_to, int *cost_to)
{
	int	i;

	i = 0;
	while (i < graph->nverti)
	{
		edge_to[i] = -1;
		cost_to[i] = i == graph->start ? 0 : INT_MAX - 1;
		i++;
	}
}

int			*graph_bellman_ford(const t_graph *graph)
{
	int	*edge_to;
	int	*cost_to;
	int	i;

	edge_to = ft_xmalloc(sizeof(int) * graph->nverti);
	cost_to = ft_xmalloc(sizeof(int) * graph->nverti);
	initialize(graph, edge_to, cost_to);
	i = 0;
	while (i++ < graph->nverti - 1)
		relax_edges(graph, edge_to, cost_to);
	free(cost_to);
	if (edge_to[graph->end] < 0)
	{
		free(edge_to);
		return (NULL);
	}
	return (edge_to);
}
