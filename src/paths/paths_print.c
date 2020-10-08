/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:15:58 by user              #+#    #+#             */
/*   Updated: 2020/10/08 11:42:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

void paths_print(const t_paths *paths, const t_graph *graph)
{
	int 		i;
	t_iterator 	*iter;

	i = 0;
	while (i < paths->npaths)
	{
		iter = iterator_from_list(paths->arr[i]);
		while (iterator_has_next(iter))
		{
			ft_putstr(graph_id2name(graph, iterator_next(iter)));
			ft_putstr(iterator_has_next(iter) ? " -> " : "\n");
		}
		iterator_delete(iter);
		i++;
	}
}
