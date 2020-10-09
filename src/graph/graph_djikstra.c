/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_djikstra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:53:26 by user              #+#    #+#             */
/*   Updated: 2020/10/09 22:45:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	set_prices(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->nnodes)
	{
		graph->nodes[i]->price_in = graph->nodes[i]->cost_in;
		graph->nodes[i]->price_out = graph->nodes[i]->cost_out;
		i++;
	}
}

static void	relax_hidden_edge(t_graph *graph, int w)
{
	t_node	*node;

	node = graph->nodes[w];
	if (node->split && node->cost_in > node->cost_out)
	{
		node->edge_in = node->edge_out;
		node->cost_in = node->cost_out;
		min_pq_insert(graph->pq, 2 * w, node->cost_in);
	}
	if (!node->split && node->cost_out > node->cost_in)
	{
		node->edge_out = node->edge_in;
		node->cost_out = node->cost_in;
		min_pq_insert(graph->pq, 2 * w + 1, node->cost_out);
	}
}

static void	relax_edge(t_graph *graph, int v, int w)
{
	t_node	*node_v;
	t_node	*node_w;

	node_v = graph->nodes[v];
	node_w = graph->nodes[w];
	if (v == graph->end || w == graph->start || node_w->parent == v)
		return ;
	else if (node_v->parent == w && node_v->cost_in < MAX_NNODES &&
			node_w->cost_out > node_v->cost_in - 1)
	{
		node_w->edge_out = v;
		node_w->cost_out = node_v->cost_in - 1 +
			node_v->price_in - node_w->price_out;
		min_pq_insert(graph->pq, w * 2 + 1, node_w->cost_out);
		relax_hidden_edge(graph, w);
	}
	else if (node_v->parent != w && node_v->cost_out < MAX_NNODES &&
			node_w->cost_in > node_v->cost_out + 1)
	{
		node_w->edge_in = v;
		node_w->cost_in = node_v->cost_out + 1 +
			node_v->price_out - node_w->price_in;
		min_pq_insert(graph->pq, w * 2, node_w->cost_in);
		relax_hidden_edge(graph, w);
	}
}

int			graph_dijkstra(t_graph *graph)
{
	t_link		*link;
	int			v;
	int			w;

	graph_reset(graph);
	min_pq_add(graph->pq, 2 * graph->start + 1, 0);
	while (min_pq_size(graph->pq) > 0)
	{
		v = min_pq_pop(graph->pq) / 2;
		link = graph->nodes[v]->edges->head;
		while (link)
		{
			w = link->content;
			relax_edge(graph, v, w);
			link = link->next;
		}
	}
	set_prices(graph);
	return (graph->nodes[graph->end]->edge_in >= 0);
}
