/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:49:06 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 12:13:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void			graph_delete(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->nverti)
		list_delete(graph->adj[i++]);
	free(graph->adj);
	array_delete(graph->names);
	free(graph);
}
