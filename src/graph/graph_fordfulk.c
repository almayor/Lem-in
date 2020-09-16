/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fordfulk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:49:54 by unite             #+#    #+#             */
/*   Updated: 2020/09/16 20:28:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		reset_flow(const t_graph *graph)
{
	t_edge	*edge;
	size_t	i;

	i = 0;
	while (i < graph->nverti)
	{
		edge = graph->adj[i];
		while (edge)
		{
			edge->flow = 0;
			edge = edge->next;
		}
		i++;
	}
}

static void		augment_flow(const t_graph *graph, int from, int to)
{
	t_edge	*edge_fwd;
	t_edge	*edge_rev;

	edge_fwd = graph->adj[from];
	while (edge_fwd->to != to)
		edge_fwd = edge_fwd->next;
	edge_fwd->flow += 1;
	edge_rev = graph->adj[to];
	while (edge_rev->to != from)
		edge_rev = edge_rev->next;
	edge_rev->flow -= 1;
}

static int		has_augmenting_path(const t_graph *graph, int *edge_to)
{
	t_queue			*queue;
	t_edge			*edge;
	int				v;
	int				w;

	queue = queue_new();
	queue_enqueue(queue, graph->start);
	while (queue_size(queue) > 0 && (v = queue_dequeue(queue)) != graph->end)
	{
		edge = graph->adj[v];
		while (edge)
		{
			w = edge->to;
			if (w != graph->start && edge->flow <= 0 && edge_to[w] == -1)
			{
				edge_to[w] = v;
				queue_enqueue(queue, w);
			}
			edge = edge->next;
		}
	}
	queue_delete(queue);
	return (edge_to[graph->end] != -1);
}

size_t			graph_fordfulk(const t_graph *graph, size_t flow)
{
	size_t	maxflow;
	int		*edge_to;
	int		w;
	int		v;

	maxflow = 0;
	reset_flow(graph);
	edge_to = ft_xmalloc(sizeof(int) * graph->nverti);
	ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
	while (maxflow < flow && has_augmenting_path(graph, edge_to))
	{
		w = graph->end;
		while (w != graph->start)
		{
			v = edge_to[w];
			augment_flow(graph, v, w);
			w = v;
		}
		ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
		maxflow++;
	}
	free(edge_to);
	return (maxflow);
}
