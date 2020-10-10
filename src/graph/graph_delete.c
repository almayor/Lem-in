/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 20:58:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void			graph_delete(t_graph *graph)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < graph->nnodes)
	{
		node = graph->nodes[i];
		list_delete(node->edges);
		free(node);
		i++;
	}
	array_delete(graph->names);
	list_delete(graph->exits);
	min_pq_delete(graph->pq);
	free(graph->nodes);
	free(graph);
}
