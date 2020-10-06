/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_from_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:35:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/06 18:50:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_node	*node_new(void)
{
	t_node	*node;

	node = ft_xcalloc(sizeof(t_node), 1);
	node->ancest = list_new();
	node->descend = list_new();
	return (node);
}

t_graph			*graph_from_names(t_array *names, const char *start_name,
								const char *end_name)
{
	t_graph	*graph;
	int		i;

	graph = ft_xcalloc(sizeof(t_graph), 1);
	graph->nverti = array_size(names);
	graph->nedges = 0;
	graph->names = names;
	graph->nodes = ft_xcalloc(sizeof(t_node *), graph->nverti);
	i = 0;
	while (i < graph->nverti)
		graph->nodes[i++] = node_new();
	array_quick_sort(names);
	graph->start = array_indexof(names, start_name);
	graph->end = array_indexof(names, end_name);
	return (graph);
}
