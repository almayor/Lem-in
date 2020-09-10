/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:38:31 by unite             #+#    #+#             */
/*   Updated: 2020/09/09 19:24:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	array_partition(t_array *array, int lo, int hi)
{
	int	i;
	int	j;

	i = lo;
	j = hi + 1;
	while (1)
	{
		while (ft_strcmp(array->arr[++i], array->arr[lo]) <= 0)
			if (i == hi)
				break ;
		while (ft_strcmp(array->arr[lo], array->arr[--j]) <= 0)
			if (j == lo)
				break ;
		if (i >= j)
			break ;
		array_swap(array, i, j);
	}
	array_swap(array, j, lo);
	return (j);
}

static void		array_quick_sort_recur(t_array *array, int lo, int hi)
{
	int	pivot;

	if (lo >= hi)
		return ;
	pivot = array_partition(array, lo, hi);
	array_quick_sort_recur(array, lo, pivot);
	array_quick_sort_recur(array, pivot + 1, hi);
}

void			array_quick_sort(t_array *array)
{
	if (array->size <= 1)
		return ;
	else if (array->size <= 7)
		array_insertion_sort(array);
	else
		array_quick_sort_recur(array, 0, array->size - 1);
}
