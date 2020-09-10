/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:27:51 by unite             #+#    #+#             */
/*   Updated: 2020/09/09 19:23:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_append(t_array *array, char *val)
{
	if (array->size == array->capacity)
		array_grow(array);
	array->arr[array->size++] = val;
}
