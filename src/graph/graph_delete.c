/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 12:37:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		node_delete(t_node *node)
{
	t_edge	*e1;
	t_edge	*e2;

	e1 = node->edges;
	while (e1)
	{
		e2 = e1->next;
		free(e1);
		e1 = e2;
	}
	free(node);
}

void			graph_delete(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->nnodes)
		node_delete(graph->nodes[i++]);
	array_delete(graph->names);
	list_delete(graph->exits);
	free(graph->nodes);
	free(graph);
}
