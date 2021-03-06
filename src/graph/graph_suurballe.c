/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_suurballe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:30:42 by user              #+#    #+#             */
/*   Updated: 2020/10/11 12:46:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	split_node(t_graph *graph, int v)
{
	if (v != graph->start && v != graph->end)
		graph->nodes[v]->split = 1;
}

static void	unsplit_node(t_graph *graph, int v)
{
	graph->nodes[v]->split = 0;
	graph->nodes[v]->parent = -1;
}

/*
** Function is solely needed to make `cache_path` 25 lines long.
*/

static void	simult_assign(int *a, int *b, int c, int d)
{
	*a = c;
	*b = d;
}

/*
** Caches the most recently found path in the graph, i.e. split / unsplit nodes
** and records the child-parent relationship of nodes in the graph
*/

static void	cache_path(t_graph *graph)
{
	int	unsplit;
	int	w;
	int	v;

	unsplit = 0;
	w = graph->end;
	v = graph->nodes[graph->end]->edge_in;
	list_add_last(graph->exits, graph->nodes[w]->edge_in);
	while (w != graph->start)
	{
		if (graph->nodes[v]->parent == w)
		{
			if (unsplit)
				unsplit_node(graph, w);
			unsplit = 1;
			simult_assign(&w, &v, v, graph->nodes[v]->edge_in);
		}
		else
		{
			graph->nodes[w]->parent = v;
			split_node(graph, w);
			unsplit = 0;
			simult_assign(&w, &v, v, graph->nodes[v]->edge_out);
		}
	}
}

int			graph_suurballe(t_graph *graph)
{
	if (graph_dijkstra(graph) == 0)
		return (0);
	cache_path(graph);
	return (1);
}
