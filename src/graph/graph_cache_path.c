/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_cache_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:11:57 by user              #+#    #+#             */
/*   Updated: 2020/10/09 13:47:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static int	get_next_parent(t_graph *graph, int v, int w)
{
	if (graph->nodes[w]->cost_in < graph->nodes[w]->cost_out)
		return (graph->nodes[w]->edge_in);
	else
		return (graph->nodes[w]->edge_out);
}

static void graph_split(t_graph *graph, int v)
{
	if (v != graph->start && v != graph->end)
		graph->nodes[v]->split = 1;
}

static void graph_unsplit(t_graph *graph, int v)
{
	graph->nodes[v]->split = 0;
	graph->nodes[v]->parent = -1;
}

void		graph_cache_path(t_graph *graph)
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
		//ft_printf("%s %s",
		//		  graph_id2name(graph, w),
		//		  v == graph->start ? "\n" : " <- ");
		if (graph->nodes[v]->parent == w)
		{
			if (unsplit)
				graph_unsplit(graph, v);
			unsplit = 1;
			w = v;
			v = graph->nodes[v]->edge_in;
		}
		else
		{
			graph->nodes[w]->parent = v;
			graph_split(graph, w);
			unsplit = 0;
			w = v;
			v = graph->nodes[v]->edge_out;
		}
	}
}
