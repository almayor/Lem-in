/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bhandari.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:30:42 by user              #+#    #+#             */
/*   Updated: 2020/10/06 19:03:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		add_path(t_graph *graph, int *edge_to)
{
	int	v;
	int	w;

	w = graph->end;
	while (w != graph->start)
	{
		v = edge_to[w];
		if (list_peek_last(graph->nodes[v]->ancest) == w)
		{
			list_pop_last(graph->nodes[v]->ancest);
			list_pop_last(graph->nodes[w]->descend);
		}
		list_add_first(graph->nodes[w]->ancest, v);
		list_add_first(graph->nodes[v]->descend, w);
		graph_remove_edge(graph, v, w);
		graph_remove_edge(graph, w, v);
		graph_add_edge(graph, w, v, -1);
		w = v;
	}
}

static t_list	*unroll_path(const t_graph *graph, int v)
{
	t_list	*path;

	path = list_new();
	while (v != graph->end)
	{
		list_add_last(path, v);
		v = list_peek_last(graph->nodes[v]->descend);
	}
	list_add_last(path, v);
	return (path);
}

static t_list	**unroll_paths(const t_graph *graph)
{
	static int	npaths;
	t_list		**paths;
	t_iterator	*iter;
	int			i;

	paths = ft_xcalloc(sizeof(t_list *), ++npaths);
	iter = iterator_from_list(graph->nodes[graph->start]->descend);
	i = 0;
	while (iterator_has_next(iter))
		paths[i++] = unroll_path(graph, iterator_next(iter));
	iterator_delete(iter);
	return (paths);
}

t_list			**graph_bhandari(t_graph *graph)
{
	t_list	**paths;
	int		*edge_to;

	if (!(edge_to = graph_bellman_ford(graph)))
		return (NULL);
	add_path(graph, edge_to);
	free(edge_to);
	return (unroll_paths(graph));
}
