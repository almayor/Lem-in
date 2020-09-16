/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:30:58 by unite             #+#    #+#             */
/*   Updated: 2020/09/16 20:34:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_list	*unroll_path(const t_graph *graph, const int *edge_to,
							int *marked)
{
	t_list	*path;
	int		v;

	if (edge_to[graph->end] < 0)
		return (NULL);
	path = list_new();
	v = graph->end;
	while (v != graph->start)
	{
		list_add_first(path, v);
		if (v != graph->end)
			marked[v] = 1;
		v = edge_to[v];
	}
	return (path);
}

static t_list	*next_path(const t_graph *graph, int *edge_to, int *marked)
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
			if (w != graph->start && edge->flow >= 0 && edge_to[w] == -1 && marked[w] == 0)
			{
				edge_to[w] = v;
				queue_enqueue(queue, w);
			}
			edge = edge->next;
		}
	}
	queue_delete(queue);
	return (unroll_path(graph, edge_to, marked));
}

size_t			graph_bfs(const t_graph *graph, t_list ***dest, size_t n)
{
	t_list	*path;
	int		*edge_to;
	int		*marked;
	size_t	i;

	*dest = ft_xcalloc(sizeof(t_list *), n);
	marked = ft_xcalloc(sizeof(int), graph->nverti);
	edge_to = ft_xcalloc(sizeof(int), graph->nverti);
	ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
	i = 0;
	while (i < n && (path = next_path(graph, edge_to, marked)))
	{
		(*dest)[i++] = path;
		ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
	}
	free(edge_to);
	free(marked);
	return (i);
}
