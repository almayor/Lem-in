/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:52:18 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 03:32:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_add_edge(t_graph *graph, int v, int w)
{
	list_add_last(graph->adj[v], w);
	list_add_last(graph->adj[w], v);
	graph->nedges++;
}
