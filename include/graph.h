/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 20:23:52 by user             ###   ########.fr       */
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

# define NEGATIVE	-1
# define POSITIVE	+1
# define FORBIDDEN	0

typedef struct	s_edge
{
	int				to;
	char			state;
	struct s_edge	*next;
}				t_edge;

# define FROM_PARENT	1
# define FROM_OTHER		0

typedef struct	s_node
{
	t_edge			*edges;
	int				parent;
	int				price;
	char			split;
	char			mode;
}				t_node;

typedef struct	s_graph
{
	int				nnodes;
	int				nedges;
	t_array			*names;
	t_node			**nodes;
	t_list			*exits;
	int				start;
	int				end;
}				t_graph;

t_graph			*graph_from_names(t_array *names, const char *start_name,
								const char *end_name);

void			graph_add_edge(t_graph *graph, int from, int to);
void			graph_set_edge(t_graph *graph, int from, int to, char state);

void			graph_delete(t_graph *graph);

int				*graph_bellman_ford(t_graph *graph);

t_list			**graph_suurballe(t_graph *graph);

int				graph_name2id(const t_graph *graph, const char *name);

const char		*graph_id2name(const t_graph *graph, int id);

#endif
