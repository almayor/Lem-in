/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_adjacency.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:24:43 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 12:28:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_iterator	*graph_adjacency(const t_graph *graph, int v)
{
	return (iterator_from_list(graph->adj[v]));
}

