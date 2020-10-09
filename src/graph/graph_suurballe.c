/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_suurballe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:30:42 by user              #+#    #+#             */
/*   Updated: 2020/10/08 17:49:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
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

//

static void		print(const t_list *path, const t_graph *graph)
{
	t_link	*link;

	link = path->head;
	while (link)
	{
		//ft_printf("%s %s",
		//	graph_id2name(graph, link->content),
		//	link->next ? " -> " : "\n");
		link = link->next;
	}
}
static t_list	**unroll_paths(const t_graph *graph)
{
	static int	npaths;
	t_list		**paths;
	t_link		*link;
	int			i;

	paths = ft_xcalloc(sizeof(t_list *), ++npaths);
	link = graph->exits->head;
	i = 0;
	//ft_puts("\nPATHS:\n");
	while (link)
	{
		paths[i] = unroll_path(graph, link->content);
		print(paths[i], graph);
		link = link->next;
		i++;
	}
	return (paths);
}

t_list			**graph_suurballe(t_graph *graph)
{
	graph_bellman_ford(graph);
	if (graph->nodes[graph->end]->edge_in < 0)
		return (0);
	graph_cache_path(graph);
	return (unroll_paths(graph));
}
