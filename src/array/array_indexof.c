/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:24:52 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 23:30:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static size_t	array_indexof_recur(const t_array *array, const char *val,
									size_t start, size_t end)
{
	int	i;
	int	cmp;

	i = start + (end - start) / 2;
	cmp = ft_strcmp(array->arr[i], val);
	if (cmp == 0)
		return (i);
	else if (end - start <= 1)
		return (-1);
	else if (cmp < 0)
		return (array_indexof_recur(array, val, i, end));
	else
		return (array_indexof_recur(array, val, start, i));
}

size_t			array_indexof(const t_array *array, const char *val)
{
	return (array_indexof_recur(array, val, 0, array->size));
}
