/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:16:16 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 00:03:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include "graph.h"
# include "stdin.h"

/*
** Extracts links from `STDIN` and adds them to the graph
** @param graph The graph
*/

void	parse_links(t_stdin *in, t_graph *graph);

/*
** Exctacts the number of ants from the `STDIN`
** @return The number of ants
*/

int		parse_nants(t_stdin *in);

/*
** Extracts rooms from `STDIN` and uses them to initialize a graph
** @return A disconnected graph with all the rooms given on the `STDIN`
*/

t_graph	*parse_rooms(t_stdin *in);

#endif
