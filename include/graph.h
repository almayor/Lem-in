/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/06 19:04:21 by user             ###   ########.fr       */
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

typedef struct	s_edge
{
	int				to;
	int				cost;
	struct s_edge	*next;
}				t_edge;

typedef struct	s_node
{
	t_edge			*edges;
	t_list			*ancest;
	t_list			*descend;
}				t_node;

typedef struct	s_graph
{
	int				nverti;
	int				nedges;
	t_array			*names;
	t_node			**nodes;
	int				start;
	int				end;
}				t_graph;

t_graph			*graph_from_names(t_array *names, const char *start_name,
								const char *end_name);

void			graph_add_edge(t_graph *graph, int from, int to, int cost);
void			graph_remove_edge(t_graph *graph, int from, int to);

t_iterator		*graph_adjacency(const t_graph *graph, int v);

void			graph_delete(t_graph *graph);

int				*graph_bellman_ford(const t_graph *graph);

t_list			**graph_bhandari(t_graph *graph);

int				graph_name2id(const t_graph *graph, const char *name);

const char		*graph_id2name(const t_graph *graph, int id);

#endif
