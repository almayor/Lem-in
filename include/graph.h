/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:26:30 by unite            ###   ########.fr       */
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


typedef struct	s_graph
{
	int 	nverti;
	int 	nedges;
	t_list	**adj;
	t_array	*names;
	int		start;
	int		end;
}				t_graph;

t_graph 		*graph_from_names(t_array *names, const char *start,
								const char *end);
void 			graph_add_edge(t_graph *graph, int v, int w);
t_iterator		*graph_adjacency(const t_graph *graph, int v);
void			graph_delete(t_graph *graph);
size_t 			graph_edkarp(const t_graph *graph, t_list ***paths, size_t n);
int				graph_name2id(const t_graph *graph, const char *name);
const char		*graph_id2name(const t_graph *graph, int id);

#endif
