/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_from_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:35:49 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 03:31:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_graph	*graph_from_names(t_array *names, const char *start, const char *end)
{
	t_graph	*graph;
	int		i;

	graph = ft_xcalloc(sizeof(t_graph), 1);
	graph->nverti = array_size(names);
	graph->nedges = 0;
	graph->adj = ft_xcalloc(sizeof(t_list *), graph->nverti);
	i = 0;
	while (i < graph->nverti)
		graph->adj[i++] = list_new();
	graph->names = names;
	array_quick_sort(names);
	graph->start = array_indexof(names, start);
	graph->end = array_indexof(names, end);
	return (graph);
}
