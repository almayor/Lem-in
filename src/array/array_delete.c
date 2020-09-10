/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:56:40 by unite             #+#    #+#             */
/*   Updated: 2020/09/08 22:43:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_delete(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size)
		free(array->arr[i++]);
	free(array->arr);
	free(array);
}
