/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:16:16 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:25:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include "graph.h"
# include "stdin.h"

void	parse_links(t_stdin *in, t_graph *graph);
int		parse_nants(t_stdin *in);
t_graph	*parse_rooms(t_stdin *in);

#endif
