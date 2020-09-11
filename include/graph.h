/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 03:27:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H

# define GRAPH_H

# include <stdlib.h>
# include "array.h"
# include "iterator.h"
# include "libftprintfgnl.h"
# include "list.h"
# include "queue.h"
# include "utils.h"

/*
** @struct s_graph
** @brief A graph represented as an array of adjacency lists
** @var s_graph::nverti
** @brief The number of vertices
** @var s_graph::nedges
** @brief The number of edges
** @var s_graph::adj
** @brief An array of lists, where the list at position `i` contains
** all vertices to which the vertex `i` is adjacent
** of a given vertex.
** @var s_graph::names
** @brief A sorted arrays of vertex names, where the string at position `i` is
** the name of the `i`th vertex
** @var s_graph::start
** @brief The index of the start vertex
** @var s_graph::end
** @brief The index of the end vertex
*/

typedef struct	s_graph
{
	int		nverti;
	int		nedges;
	t_list	**adj;
	t_array	*names;
	int		start;
	int		end;
}				t_graph;

/*
** Creates a graph with vertices having specified names and no edges between
** them
** @param names	A (possibly unsorted) array of vertex names
** @param start	The name of the start vertex
** @param end	The name of the end vertex
** @return A new graph
*/

t_graph			*graph_from_names(t_array *names, const char *start,
								const char *end);

/*
** Adds an edge between vertices `v` and `w`
** @param v	One vertex
** @param w	The other vertex
*/

void			graph_add_edge(t_graph *graph, int v, int w);

/*
** Returns an iterator over the vertices adjacent to a given vertex
** @param v The vertex
** @return The iterator ove the adjacent vertices
*/

t_iterator		*graph_adjacency(const t_graph *graph, int v);

/*
** Frees all memory taken by a graph
*/

void			graph_delete(t_graph *graph);

/*
** Run Edwards-Karp algorithm on the graph, seeking at most `n` independent
** paths from `start` to `end`
** @param[out] paths The pointer where an array of paths, each represented
** by a list of vertices on each path, will be written
** @param[in] n The maximum number of paths to compute
** @return The number of paths actually found
*/

size_t			graph_edkarp(const t_graph *graph, t_list ***paths, size_t n);

/*
** Converts a vertex name to the corresponding numeric id
** @param name A vertex name
** @return The corresponding numeric id
*/

int				graph_name2id(const t_graph *graph, const char *name);

/*
** Convertex a numeric id to the corresponding vertex name
** @param id A numeric id
** @return The corresponding vertex name
*/

const char		*graph_id2name(const t_graph *graph, int id);

#endif
