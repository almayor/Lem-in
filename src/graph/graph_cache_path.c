/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_cache_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:11:57 by user              #+#    #+#             */
/*   Updated: 2020/10/08 17:49:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static int	get_new_parent(t_graph *graph, int w)
{
	if (graph->nodes[w]->cost_in < graph->nodes[w]->cost_out)
		return (graph->nodes[w]->edge_in);
	else
		return (graph->nodes[w]->edge_out);
}

void		graph_cache_path(t_graph *graph)
{
	int	unsplit;
	int	w;
	int	v;

	unsplit = 0;
	w = graph->end;
	list_add_last(graph->exits, w);
	while (w != graph->start)
	{
		v = get_new_parent(graph, w);
		if (graph->nodes[v]->parent == w)
		{
			if (unsplit)
				graph->nodes[v]->parent = -1;
			unsplit = 1;
		}
		else
		{
			graph->nodes[w]->parent = v;
			unsplit = 0;
		}
		w = v;
	}
}
