/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/10/06 18:53:17 by user             ###   ########.fr       */
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
	list_delete(node->ancest);
	list_delete(node->descend);
	free(node);
}

void			graph_delete(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->nverti)
		node_delete(graph->nodes[i++]);
	array_delete(graph->names);
	free(graph->nodes);
	free(graph);
}
