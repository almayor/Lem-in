/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 23:55:22 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 12:53:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "graph.h"
#include "stdin.h"
#include "libftprintfgnl.h"
#include "array.h"

static char	*parse_name(const char *line)
{
	char	**tab;
	char	*name;

	if (!(tab = ft_strsplit(line, ' ')))
		terminate(ERR_NO_MEMORY);
	if (tab_len(tab) != 3 || !is_room(tab[0]) ||
		!is_coord(tab[1]) || !is_coord(tab[2]))
		terminate(ERR_INVALID_INPUT);
	name = tab[0];
	free(tab[1]);
	free(tab[2]);
	free(tab);
	return (name);
}

static void parse_start(t_stdin *in, t_array *names, char **start)
{
	if (*start)
		terminate(ERR_INVALID_INPUT);
	*start = parse_name(stdin_next(in));
	array_append(names, *start);
}

static void parse_end(t_stdin *in, t_array *names, char **end)
{
	if (*end)
		terminate(ERR_INVALID_INPUT);
	*end = parse_name(stdin_next(in));
	array_append(names, *end);
}

static void	parse_default(t_stdin *in, t_array *names)
{
	array_append(names, parse_name(stdin_peek(in)));
}

t_graph		*parse_rooms(t_stdin *in)
{
	t_array	*names;
	char 	*start;
	char 	*end;

	names = array_new();
	start = NULL;
	end = NULL;
	while (stdin_next(in) && !is_link(stdin_peek(in)))
	{
		if (is_start(stdin_peek(in)))
			parse_start(in, names, &start);
		else if (is_end(stdin_peek(in)))
			parse_end(in, names, &end);
		else if (!is_comment(stdin_peek(in)))
			parse_default(in, names);
	}
	if (!start || !end)
		terminate(ERR_INVALID_INPUT);
	return (graph_from_names(names, start, end));
}
