/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/10/08 21:46:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H

# define GRAPH_H

# include <stdlib.h>
# include "array.h"
# include "libftprintfgnl.h"
# include "list.h"
# include "queue.h"
# include "utils.h"

typedef struct	s_node
{
	t_list			*edges;
	int				parent;
	int				price;
	char			split;
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
}				t_graph;

void	graph_add_edge(t_graph *graph, int v, int w);
void	graph_bellman_ford(t_graph *graph);
void	graph_cache_path(t_graph *graph);
void	graph_delete(t_graph *graph);
t_graph	*graph_from_names(t_array *names, const char *start_name,const char *end_name);
const char	*graph_id2name(const t_graph *graph, int id);
int	graph_name2id(const t_graph *graph, const char *name);
void	graph_relax_edge(t_graph *graph, int v, int w);
void	graph_reset(t_graph *graph);
t_list	**graph_suurballe(t_graph *graph);

#endif
