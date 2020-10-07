/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_suurballe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:30:42 by user              #+#    #+#             */
/*   Updated: 2020/10/07 12:34:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		set_path(t_graph *graph, int *edge_to)
{
	int	v;
	int	w;

	w = graph->end;
	while (w != graph->start)
	{
		v = edge_to[w];
		if (graph->nodes[v]->parent == w)
		{
			graph_set_edge(graph, v, w, POSITIVE);
			graph_set_edge(graph, w, v, POSITIVE);
		}
		else
		{
			graph_set_edge(graph, v, w, FORBIDDEN);
			graph_set_edge(graph, w, v, NEGATIVE);
			graph->nodes[w]->parent = v;
		}
		if (w != graph->end)
			graph->nodes[w]->split = 1;
		w = v;
	}
}

static t_list	*unroll_path(const t_graph *graph, int v)
{
	t_list	*path;

	path = list_new();
	list_add_first(path, graph->end);
	while (v != graph->start)
	{
		list_add_first(path, v);
		v = graph->nodes[v]->parent;
	}
	return (path);
}

static t_list	**unroll_paths(const t_graph *graph)
{
	static int	npaths;
	t_list		**paths;
	t_iterator	*iter;
	int			i;

	paths = ft_xcalloc(sizeof(t_list *), ++npaths);
	iter = iterator_from_list(graph->exits);
	i = 0;
	while (iterator_has_next(iter))
		paths[i++] = unroll_path(graph, iterator_next(iter));
	iterator_delete(iter);
	return (paths);
}

void 			print_path_edge_to(const t_graph *graph, const int *edge_to)
{
	int v = graph->end;
	t_list	*list = list_new();
	while (v != graph->start)
	{
		list_add_last(list, v);
		ft_printf("%i\n", v);
		v = edge_to[v];
	}
	list_print(list);
	list_delete(list);
}

t_list			**graph_suurballe(t_graph *graph)
{
	t_list	**paths;
	int		*edge_to;

	if (!(edge_to = graph_bellman_ford(graph)))
		return (NULL);
	list_add_last(graph->exits, edge_to[graph->end]);
	set_path(graph, edge_to);
	free(edge_to);
	return (unroll_paths(graph));
}
