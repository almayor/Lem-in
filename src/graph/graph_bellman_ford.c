/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bellman_ford.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:49:47 by user              #+#    #+#             */
/*   Updated: 2020/10/07 12:39:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <limits.h>
#include <assert.h>

static int	available(const t_node *node, const t_edge *edge)
{
	if (edge->state == FORBIDDEN)
		return (0);
	if (node->split == 0)
		return (1);
	if (node->mode == FROM_PARENT)
		return (1);
	else
		return (edge->state == NEGATIVE);
}

static void	update_mode(t_graph *graph, int from, int to)
{
	if (graph->nodes[from]->parent == to)
		graph->nodes[to]->mode = FROM_PARENT;
	else
		graph->nodes[to]->mode = FROM_OTHER;
}

static void	relax_edges(t_graph *graph, int *edge_to, int *cost_to)
{
	int			v;
	int			w;
	int			c;
	t_edge		*edge;

	v = 0;
	while (v < graph->nnodes)
	{
		edge = graph->nodes[v]->edges;
		while (edge)
		{
			w = edge->to;
			c = edge->state;
			if (v != graph->end && w != graph->start &&
				available(graph->nodes[v], edge) &&
				cost_to[w] > cost_to[v] + c)
			{
				edge_to[w] = v;
				cost_to[w] = cost_to[v] + c;
				update_mode(graph, v, w);
				//assert(cost_to[w] >= 0);
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
	while (i < graph->nnodes)
	{
		edge_to[i] = -1;
		cost_to[i] = i == graph->start ? 0 : INT_MAX - 1;
		i++;
	}
}

int			*graph_bellman_ford(t_graph *graph)
{
	int	*edge_to;
	int	*cost_to;
	int	i;

	edge_to = ft_xmalloc(sizeof(int) * graph->nnodes);
	cost_to = ft_xmalloc(sizeof(int) * graph->nnodes);
	initialize(graph, edge_to, cost_to);
	i = 0;
	while (i++ < graph->nnodes - 1)
		relax_edges(graph, edge_to, cost_to);
	free(cost_to);
	if (edge_to[graph->end] < 0)
	{
		free(edge_to);
		return (NULL);
	}
	return (edge_to);
}
