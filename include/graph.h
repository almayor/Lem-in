/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:05:30 by user             ###   ########.fr       */
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

# define MAX_NNODES	100000

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

void	graph_add_edge(t_graph *graph, int v, int w);
void	graph_delete(t_graph *graph);
int		graph_dijkstra(t_graph *graph);
t_graph	*graph_from_names(t_array *names, const char *start_name,const char *end_name);
const char	*graph_id2name(const t_graph *graph, int id);
int		graph_name2id(const t_graph *graph, const char *name);
void	graph_reset(t_graph *graph);
int		graph_suurballe(t_graph *graph);

#endif
