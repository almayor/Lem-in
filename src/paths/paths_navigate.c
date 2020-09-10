/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_navigate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:03:33 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:04:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

t_iterator	*paths_navigate(t_paths *paths, size_t i)
{
	t_iterator	*iter;

	iter = iterator_from_list(paths->arr[i]);
	paths->assignments[i] -= 1;
	return (iter);
}
