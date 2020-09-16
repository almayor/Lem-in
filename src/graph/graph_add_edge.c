/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:52:18 by unite             #+#    #+#             */
/*   Updated: 2020/09/16 17:11:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_add_edge(t_graph *graph, int v, int w)
{
	t_edge	*edge_v;
	t_edge	*edge_w;

	edge_v = ft_xcalloc(sizeof(t_edge), 1);
	edge_v->to = w;
	edge_v->next = graph->adj[v];
	graph->adj[v] = edge_v;
	edge_w = ft_xcalloc(sizeof(t_edge), 1);
	edge_w->to = v;
	edge_w->next = graph->adj[w];
	graph->adj[w] = edge_w;
	graph->nedges++;
}
