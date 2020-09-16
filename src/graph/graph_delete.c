/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/09/16 17:13:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		adjacency_delete(t_edge *edge)
{
	t_edge	*next;

	while (edge)
	{
		next = edge->next;
		free(edge);
		edge = next;
	}
}

void			graph_delete(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->nverti)
		adjacency_delete(graph->adj[i++]);
	free(graph->adj);
	array_delete(graph->names);
	free(graph);
}
