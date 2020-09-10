/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:16:40 by unite             #+#    #+#             */
/*   Updated: 2020/09/08 22:43:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	array_insert_next(t_array *array, int j)
{
	while (j > 0)
	{
		if (ft_strcmp(array_get(array, j), array_get(array, j - 1)) < 0)
			array_swap(array, j, j - 1);
		else
			break ;
		j--;
	}
}

void		array_insertion_sort(t_array *array)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < array->size - 1)
	{
		if (ft_strcmp(array_get(array, i), array_get(array, i + 1)) > 0)
			array_insert_next(array, i + 1);
		i++;
	}
}
