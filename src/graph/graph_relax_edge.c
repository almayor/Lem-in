/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_relax_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:08:53 by user              #+#    #+#             */
/*   Updated: 2020/10/08 17:49:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	relax_hidden_edge(t_graph *graph, int w)
{
	t_node	*node;

	node = graph->nodes[w];
	if (node->split && node->cost_in > node->cost_out)
	{
		node->cost_in = node->cost_out;
		node->edge_in = node->edge_out;
	}
	if (!node->split && node->cost_out > node->cost_in)
	{
		node->cost_out = node->cost_in;
		node->edge_out = node->edge_in;
	}
}

void	graph_relax_edge(t_graph *graph, int v, int w)
{
	t_node	*node_v;
	t_node	*node_w;

	node_v = graph->nodes[v];
	node_w = graph->nodes[w];
	if (v == graph->end || w == graph->start)
		return ;
	else if (node_w->parent == v)
		return ;
	else if (node_v->parent == w && node_w->cost_out > node_v->cost_in - 1)
	{
		node_w->edge_out = v;
		node_w->cost_out = node_v->cost_in - 1;
		relax_hidden_edge(graph, w);
	}
	else if (node_v->parent != w && node_w->cost_in > node_v->cost_out + 1)
	{
		node_w->edge_in = v;
		node_w->cost_in = node_v->cost_out + 1;
		relax_hidden_edge(graph, w);
	}
}
