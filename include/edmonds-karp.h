/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds-karp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:07:46 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:20:32 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDMONDS_KARP_H
# define EDMONDS_KARP_H

/*
** @struct s_edkarp
** A data structure representing the current state of the Edmonds–Karp algorithm
** @var s_edkarp::graph
** The graph on which the algorithm is running
** @var s_edkarp::source
** The source vertex
** @var s_edkarp::sink
** The sink vertex
** @var s_edkarp::marked
** A boolean array denoting which vertices have already been saturated.
** @details In this project, we consider only undirected graphs where all
** vertices have a capacity of 1. Therefore, instead of considering which edges
** are saturated, we only keep account of saturated vertices.
*/
typedef struct s_edkarp
{
	const t_graph	*graph;
	int				source;
	int				sink;
	int				*marked;
}				t_edkarp

/*
** Allocates memory and initializes a data-structure, representing
** the current state of the Edmonds–Karp algorithm.
** @param graph The graph to consider
** @param source The source vertex
** @param sink The sink vertex
** @return Pointer to the newly allocated memory or `NULL` on failure
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The source or sink are not graph vertices, or the graph
**						is `NULL` / invalid
*/
t_edkarp		*make_edkarp(const t_graph *graph, int source, int sink);

/*
** Computes the next augmenting (shortest) path from source to sink, given
** the current state of the Edmonds-Karp algorithm
** @param edkarp	A data structure representing the current state of
** the Edmonds-Karp algorithm
** @return The list of vertices on the next path from the source to the sink,
** or `NULL` if no more paths exist. 
*/
t_list			*path_edkarp(t_edkarp *edkarp);

/*
** Frees all memory taken by the Edmonds-Karp algorithm or does nothing if
** `edkarp` is `NULL`.
** @param edkarp The current state of the Edmonds-Karp algorithm
*/
void 			free_edkarp(t_edkarp *edkarp);

#endif
