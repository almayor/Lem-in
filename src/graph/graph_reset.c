/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:34:05 by user              #+#    #+#             */
/*   Updated: 2020/10/08 17:37:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_reset(t_graph *graph)
{
	int		v;
	t_node	*node;

	v = 0;
	while (v < graph->nnodes)
	{
		node = graph->nodes[v];
		node->edge_in = -1;
		node->edge_out = -1;
		node->cost_in = INT_MAX - 1;
		node->cost_out = INT_MAX - 1;
		v++;
	}
	node = graph->nodes[graph->start];
	node->cost_in = 0;
	node->cost_out = 0;
}
