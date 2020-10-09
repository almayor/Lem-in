/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dijkstra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 02:13:02 by unite             #+#    #+#             */
/*   Updated: 2020/09/18 05:47:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		relax(t_edge *edge, int *dist, int *prev, t_min_pq *pq)
{
	int	v;
	int	w;

	v = edge->from;
	w = edge->to;
	if (dist[w] < 0 || dist[w] > dist[v] + edge->weight)
	{
		dist[w] = dist[v] + edge->weight;
		prev[w] = v;
		if (min_pq_contains(pq, w))
			min_pq_add(pq, w, dist[w]);
		else
			min_pq_change(pq, w, dist[w]);
	}
}

static void		run(const t_graph *graph, int *dist, int *prev, t_min_pq *pq)
{
	int		v;
	int		w;
	t_edge	*edge;

	dist[graph->start] = 0;
	min_pq_add(pq, graph->start, 0);
	while (min_pq_size(pq) > 0)
	{
		v = min_pq_pop(pq);
		edge = graph->adj[v];
		while (edge)
		{
			w = edge->to;
			relax(graph, *dist, prev);
			min_pq_add(pq, w, dist[w]);
			edge = edge->next;
		}
	}
}

static t_list	*unroll(const t_graph *graph, int *prev)
{
	t_list	*path;
	int		w;

	w = graph->end;
	if (w < 0)
		return (NULL);
	path = list_new();
	while (w != graph->start)
	{
		list_add_last(path, w);
		w = prev[w];
	}
	return (path);
}

t_list			*graph_dijkstra(const t_graph *graph, int **dist)
{
	int			*prev;
	t_min_pq	*pq;
	t_list		*path;

	*dist = ft_xcalloc(sizeof(int), graph->nverti);
	prev = ft_xcalloc(sizeof(int), graph->nverti);
	ft_memset(*dist, -1, sizeof(int) * graph->nverti);
	ft_memset(prev, -1, sizeof(int) * graph->nverti);
	pq = min_pq_new(graph->nverti);
	run(graph, *dist, prev, pq);
	path = unroll(graph, prev);
	free(prev);
	min_pq_delete(pq);
	return (path);
}
