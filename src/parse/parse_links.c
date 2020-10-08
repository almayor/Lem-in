/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:04:28 by unite             #+#    #+#             */
/*   Updated: 2020/10/08 17:46:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "stdin.h"
#include "libftprintfgnl.h"
#include "utils.h"

void	parse_links(t_stdin *in, t_graph *graph)
{
	char	**tab;
	int		room1;
	int		room2;

	while (stdin_peek(in))
	{
		if (!is_comment(stdin_peek(in)))
		{
			if (!(tab = ft_strsplit(stdin_peek(in), '-')))
				terminate(ERR_NO_MEMORY);
			if (tab_len(tab) != 2 ||
				(room1 = graph_name2id(graph, tab[0])) < 0 ||
				(room2 = graph_name2id(graph, tab[1])) < 0)
				terminate(ERR_INVALID_INPUT);
			graph_add_edge(graph, room1, room2);
			graph_add_edge(graph, room2, room1);
			tab_delete(tab);
		}
		stdin_next(in);
	}
}
