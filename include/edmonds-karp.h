/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds-karp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:07:46 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 19:25:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDMONDS_KARP_H
# define EDMONDS_KARP_H

/*
** @struct s_ekalg
** A data structure representing the current state of the Edmonds–Karp algorithm
** @var s_ekalg::graph
** The graph on which the algorithm is running
** @var s_ekalg::source
** The source vertex
** @var s_ekalg::sink
** The sink vertex
** @var s_ekalg::marked
** A boolean array denoting which vertices have already been saturated.
** @details In this project, we consider only undirected graphs where all
** vertices have capacity of 1. Therefore, instead of considering which edges
** are saturated, we only keep account of saturated vertices.
*/
typedef struct s_ekalg
{
	const t_graph	*graph;
	int				source;
	int				sink;
	int				*marked;
}				s_ekalg

/*
** Allocates memory and initializes a data-structure, representing
** the current state of the Edmonds–Karp algorithm.
** @param graph The graph to consider
** @param source The source vertex
** @param sink The sink vertex
** @return Pointer to the newly allocated memory or `NULL` on failure
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The source or sink are not graph vertices, the graph
**						is `NULL` or invalid
*/
s_ekalg	*make_ekalg(const t_graph *graph, int source, int sink);

/*
** Computes the next augmenting (shortest) path from source to sink, given
** the current state of the Edmonds-Karp algorithm
** @param ekalg	A data structure representing the current state of
** the Edmonds-Karp algorithm
** @return The list of vertices on the next path from source to sink, or `NULL`
** no more paths exist. 
*/
t_list	*path_ekalg(s_ekalg *ekalg);

/*
** Frees all memory taken by the Edmonds-Karp algorithm or does nothing if
** `ekalg` is `NULL`.
** @param ekalg The current state of the Edmonds-Karp algorithm
*/
void 	free_ekalg(s_ekalg *ekalg);

#endif
