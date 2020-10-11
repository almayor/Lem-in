/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/11 13:05:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H

# define GRAPH_H

# include <stdlib.h>
# include "array.h"
# include "libftprintfgnl.h"
# include "list.h"
# include "min_pq.h"
# include "utils.h"

/*
** The maxmimum number of nodes in the graph
** @note Should be less than `INT_MAX`
*/

# define MAX_NNODES	100000

/*
** @struct s_node
** @brief A node in the graph
** @var s_node::edges
** @brief A list of ids of nodes that this node has an edge to
** @var s_node::parent
** @brief The id of the node that lies ahead of the current node
** on the path that it belongs to
** @var s_node::split
** @brief A boolean flag denoting if the node is split
** @var s_node::price_in
** @brief The price function value to the IN half of a split node
** @var s_node::price_out
** @brief The price function value to the OUT half of a split node
** @var s_node::edge_in
** @brief The incoming edge to the IN half of a split node
** (used during Dijkstra's algorithm run)
** @var s_node::edge_out
** @brief The incoming edge to the OUT half of a split node
** (used during Dijkstra's algorithm run)
** @var s_node::cost_in
** @brief The cost to the IN half of a split node
** (used during Dijkstra's algorithm run)
** @var s_node::cost_out
** @brief The cost to the OUT half of a split node
** (used during Dijkstra's algorithm run)
*/

typedef struct	s_node
{
	t_list			*edges;
	int				parent;
	char			split;
	int				price_in;
	int				price_out;
	int				edge_in;
	int				edge_out;
	int				cost_in;
	int				cost_out;
}				t_node;

/*
** @struct s_graph
** @brief A graph
** @var s_graph::nnodes
** @brief The number of nodes in the graph
** @var s_graph::nedges
** @brief The number of directed edges in the graph
** @var s_graph::names
** @brief An array of names of graph nodes
** @var s_graph::nodes
** @brief An array of graph nodes
** @details For example, `names[1]` is the name of the node with an id of `1`
** @var s_graph::exits
** @brief A list of ids of exit nodes (i.e. nodes just preceding the end node)
** from paths that have thus far been found in the graph
** @var s_graph::start
** @brief The id of the start node
** @var s_graph::end
** @brief The id of the end node
** @var s_graph::pq
** @brief A priority queue (used during Dijkstra's algorithm run)
*/

typedef struct	s_graph
{
	int				nnodes;
	int				nedges;
	t_array			*names;
	t_node			**nodes;
	t_list			*exits;
	int				start;
	int				end;
	t_min_pq		*pq;
}				t_graph;

/*
** Generates a graph from an array of node names, as well as the given
** start and end nodes
** @param names An array of node names
** @param start_name The name of the start node
** @param end_name The name of the end node
** @return The graph
*/

t_graph			*graph_from_names(t_array *names, const char *start_name,
							const char *end_name);

/*
** Returns the name of the node with a given id
** @param id The id of the node
** @return The name of the node
*/

const char		*graph_id2name(const t_graph *graph, int id);

/*
** Returns the id of the node with a given name
** @param name The name of the node
** @return The id of the node
*/

int				graph_name2id(const t_graph *graph, const char *name);

/*
** Adds two directed between edges going in the opposite directions
** connecting two nodes in the graph
** @param v The id of one node
** @param w The id of the other node
*/

void			graph_add_edge(t_graph *graph, int v, int w);

/*
** Runs Dijkstra's algorithm to find the shortest path from the start to
** the end node of the graph
** @return `1` if a path exists, `0` otherwise
*/

int				graph_dijkstra(t_graph *graph);

/*
** Runs Suurballe's algorithm to add a node-disjoint path between the start
** and end nodes in the graph, such that the paths have minimum total length.
** @details Successive calls to this function add one more path to the graph
** @return `1` if another path can be added, `0` otherwise
*/

int				graph_suurballe(t_graph *graph);

/*
** Resets the graph in preparation for the next run of Dijkstra's algorithm
** @note This function should not be called externally
*/

void			graph_reset(t_graph *graph);

/*
** Deletes the graph and frees all of its data
*/

void			graph_delete(t_graph *graph);

#endif
