/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_remove_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 18:58:10 by user              #+#    #+#             */
/*   Updated: 2020/10/06 19:02:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_remove_edge(t_graph *graph, int from, int to)
{
	t_edge	*edge;
	t_edge	*tmp;

	graph->nedges--;
	edge = graph->nodes[from]->edges;
	if (edge->to == to)
	{
		graph->nodes[from]->edges = edge->next;
		free(edge);
		return ;
	}
	while (edge && edge->next)
	{
		if (edge->next && edge->next->to == to)
		{
			tmp = edge->next;
			edge->next = edge->next->next;
			free(tmp);
			return ;
		}
		edge = edge->next;
	}
}
