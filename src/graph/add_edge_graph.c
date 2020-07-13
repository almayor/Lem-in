/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:52:18 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:57:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int add_edge_graph(t_graph *graph, int v, int w)
{
	if (graph == NULL || graph->adj == NULL ||
		v < 0 || v >= graph->V || w < 0 || w >= graph->V ||
		graph->adj[v] == NULL || graph->adj[w] == NULL)
	{
		errno = EINVAL;
		return (1);
	}
	if (!(graph->adj[v] = add_list(graph->adj[v], w)) ||
		!(graph->adj[w] = add_list(graph->adj[w], v)))
	{
		errno = ENOMEM;
		return (1);
	}
	graph->E++;
	return (0);
}
