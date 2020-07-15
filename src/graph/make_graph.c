/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:35:49 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 16:23:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_graph 		*make_graph(int V)
{
	t_graph	*graph;
	int		i;

	if (!(graph = ft_calloc(sizeof(graph), 1)) ||
		!(graph->adj = ft_calloc(sizeof(t_list *), V)) ||
		!(graph->vertex_names) = ft_calloc(sizeof(char *), V))
	{
		free_graph(graph);
		return (NULL);
	}
	graph.V = V;
	graph.E = 0;
	i = 0;
	while (i < V)
	{
		if (!(graph->adj[i] = make_list()))
		{
			free_graph(graph);
			return (NULL);
		}
		i++;
	}
	return (graph);
}
