/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_from_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:32:56 by user              #+#    #+#             */
/*   Updated: 2020/10/09 20:44:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

static t_list	*unroll_path(const t_graph *graph, int v)
{
	t_list	*path;

	path = list_new();
	list_add_first(path, graph->end);
	while (v != graph->start)
	{
		list_add_first(path, v);
		v = graph->nodes[v]->parent;
	}
	return (path);
}

t_paths			*paths_from_graph(const t_graph *graph, size_t nants)
{
	t_paths		*paths;
	t_link		*link;
	int			i;

	paths = ft_xcalloc(sizeof(t_paths), 1);
	paths->npaths = list_size(graph->exits);
	paths->assignments = ft_xcalloc(sizeof(size_t), nants);
	paths->arr = ft_xcalloc(sizeof(t_list *), paths->npaths);
	link = graph->exits->head;
	i = 0;
	while (link)
	{
		paths->arr[i] = unroll_path(graph, link->content);
		link = link->next;
		i++;
	}
	paths_assign(paths, nants);
	return (paths);
}
