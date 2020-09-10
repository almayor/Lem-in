/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:52:45 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 15:53:39 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

void	paths_delete(t_paths *paths)
{
	size_t	i;

	i = 0;
	while (i < paths->npaths)
		list_delete(paths->arr[i++]);
	free(paths->assignments);
	free(paths);
}
