/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_from_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:35:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 17:44:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_node	*node_new(void)
{
	t_node	*node;

	node = ft_xcalloc(sizeof(t_node), 1);
	node->parent = -1;
	node->child = -1;
	return (node);
}

t_graph			*graph_from_names(t_array *names, const char *start_name,
								const char *end_name)
{
	t_graph	*graph;
	int		i;

	graph = ft_xcalloc(sizeof(t_graph), 1);
	graph->nnodes = array_size(names);
	graph->nedges = 0;
	graph->names = names;
	graph->nodes = ft_xcalloc(sizeof(t_node *), graph->nnodes);
	graph->exits = list_new();
	i = 0;
	while (i < graph->nnodes)
		graph->nodes[i++] = node_new();
	array_quick_sort(names);
	graph->start = graph_name2id(graph, start_name);
	graph->end = graph_name2id(graph, end_name);
	return (graph);
}
