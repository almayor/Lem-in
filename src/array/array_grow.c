/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_grow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:23:06 by unite             #+#    #+#             */
/*   Updated: 2020/09/09 19:23:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_grow(t_array *array)
{
	char	**arr;
	int		i;

	arr = ft_xmalloc(sizeof(char *) * array->capacity * 2);
	i = 0;
	while (i < array->size)
	{
		arr[i] = array->arr[i];
		i++;
	}
	array->capacity = array->capacity * 2;
	free(array->arr);
	array->arr = arr;
}
