/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_set_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:38:20 by user              #+#    #+#             */
/*   Updated: 2020/10/07 12:41:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_set_edge(t_graph *graph, int from, int to, char state)
{
	t_edge	*edge;

	edge = graph->nodes[from]->edges;
	while (edge)
	{
		if (edge->to == to)
		{
			edge->state = state;
			return ;
		}
		edge = edge->next;
	}
}
