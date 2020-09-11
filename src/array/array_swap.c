/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:18:30 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 03:29:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_swap(t_array *array, size_t ind1, size_t ind2)
{
	char	*content;

	content = array->arr[ind1];
	array->arr[ind1] = array->arr[ind2];
	array->arr[ind2] = content;
}
