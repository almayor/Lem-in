/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:52:18 by unite             #+#    #+#             */
/*   Updated: 2020/10/08 17:45:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_add_edge(t_graph *graph, int v, int w)
{
	list_add_first(graph->nodes[v]->edges, w);
	graph->nedges++;
}
