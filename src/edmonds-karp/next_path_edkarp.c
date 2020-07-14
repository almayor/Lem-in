/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_path_edkarp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:39:57 by unite             #+#    #+#             */
/*   Updated: 2020/07/14 13:43:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edmonds-karp.h"

static t_list	*unroll_path_edkarp(t_edkarp *edkarp,
									int *edge_to, int *dist_to)
{
	int		v;
	t_list	*path;

	if (!dist_to[v] || !(path = make_list()))
		return (NULL);
	v = edkarp->sink;
	while (v != edkarp->source)
	{
		add_list(path, v);
		v = edkarp->edge_to[v];
	}
	return (path);
}

static void		mark_edkarp(t_edkarp *edkarp, t_list *path)
{
	int		v;
	while (path)
	{
		v = path->val;
		if (v != edkarp->source && v != edkarp->sink)
			edkarp->marked[v] = 1;
		path = path->next;
	}
}

static t_list	*bfs_edkarp(t_edkarp *edkarp, t_queue *queue,
							int *edge_to, int *dist_to)
{
	int		v;
	t_list	*link;

	enqueue_queue(queue, edkarp->source);
	while (queue->size > 0)
	{
		v = dequeue_queue(queue);
		if (v == edkarp->sink)
			break ;
		link = edkarp->graph->adj[v];
		while (link)
		{
			if (dist_to[link->val] == 0 && !edkarp->marked[link->val])
			{
				edge_to[link->val] = v;
				dist_to[link->val] = dist_to[v] + 1;
				enqueue_queue(queue, link->val);
			}
			link = link->next;
		}
	}
	return (unroll_path(edkarp, edge_to, dist_to));
}

t_list			*next_path_edkarp(t_edkarp *edkarp)
{
	t_queue	*queue;
	int		*edge_to;
	int		*dist_to;
	t_list	*path;
	
	if (edkarp->sink == edkarp->source)
		return (make_list());
	if ((queue = make_queue()) &&
		(edge_to = ft_calloc(sizeof(int), edkarp->graph->V)) &&
		(dist_to = ft_calloc(sizeof(int), edkarp->graph->V)))
	{
		if ((path = bfs_edkarp(edkarp, queue, edge_to, dist_to)))
			mark_edkarp(edkarp, path);
	}
	free_queue(queue);
	free(edge_to);
	free(dist_to);
	if (errno)
	{
		free_list(path);
		return (NULL);
	}
	return (path);	
}
