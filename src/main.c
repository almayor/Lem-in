/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:27:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 23:57:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libftprintfgnl.h"
#include "map.h"
#include "list.h"
#include "farm.h"
#include "edmonds-karp.h"

static int		get_n_ants(void);
static t_map	*get_vertex_names(void);
static t_list	**get_paths(int n_ants, t_map *vertex_names);
static int		get_n_paths(t_list **paths);
	
int main(void)
{
	t_map	*vertex_names;
	t_list	**paths;
	t_farm	*farm;
	int		n_paths;
	int		n_ants;

	if ((n_ants = get_n_ants()) &&
		(vertex_names = get_vertex_names()) &&
		(paths = get_paths(n_ants, vertex_names)) &&
		(n_paths = get_n_paths(paths)) &&
		(farm = make_farm(n_ants)))
		run_farm(farm, paths, n_paths, vertex_names);
	free_farm(farm);
	free_paths(paths);
	free_map(vertex_names);
}
