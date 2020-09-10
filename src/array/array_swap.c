/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:18:30 by unite             #+#    #+#             */
/*   Updated: 2020/09/08 22:43:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_swap(t_array *array, int ind1, int ind2)
{
	char	*content;

	content = array->arr[ind1];
	array->arr[ind1] = array->arr[ind2];
	array->arr[ind2] = content; 
}
