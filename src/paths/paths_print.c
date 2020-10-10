/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:15:58 by user              #+#    #+#             */
/*   Updated: 2020/10/10 23:36:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

void	paths_print(const t_paths *paths, const t_graph *graph)
{
	int		i;
	t_link	*link;

	i = 0;
	while (i < paths->npaths)
	{
		link = paths->arr[i]->head;
		while (link)
		{
			ft_putstr(graph_id2name(graph, link->content));
			link = link->next;
			ft_putstr(link ? " -> " : "\n");
		}
		i++;
	}
}
