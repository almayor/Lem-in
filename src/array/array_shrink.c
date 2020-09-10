/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 23:26:57 by unite             #+#    #+#             */
/*   Updated: 2020/09/09 19:23:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_shrink(t_array *array)
{
	char	**arr;
	int		i;

	arr = ft_xmalloc(sizeof(char *) * array->size * 2);
	i = 0;
	while (i < array->size)
	{
		arr[i] = array->arr[i];
		i++;
	}
	array->capacity = array->size * 2;
	free(array->arr);
	array->arr = arr;
}
