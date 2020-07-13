/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:52:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

#include <errno.h>
#include "libftprintfgnl.h"
#include "list.h"

/*
** @struct s_graph
** An adjacency-list representation of an undirected graph
** @var s_graph::V
** Number of vertices
** @var s_graph::E
** Number of edges
** @var s_graph::adj
** The array of adjacency lists
** @details For every vertex, the array holds a list of vertices that
** this vertex shares an edge with.
*/
typedef struct	s_graph
{
	int 	V;
	int 	E;
	t_list	**adj;
}				t_graph;

/*
** Allocates memory and initializes a graph data-structure.
** @return Pointer to the newly allocated memory or `NULL` on failure
** @exception ENOMEM	Memory allocation error
*/
t_graph 		*make_graph(int V);

/*
** Adds an edge between two vertices to a graph
** @param v One vertex sharing the edge
** @param w The other vertex sharing the edge
** @param graph The graph
** @return 0 on success, 1 on failure
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The graph is `NULL` or invalid
*/
int 			add_edge_graph(t_graph *graph, int v, int w);

/*
** Frees all memory taken by a graph or does nothing if the graph is `NULL`.
** @param graph The graph
*/
void			free_graph(t_graph *graph);

#endif
