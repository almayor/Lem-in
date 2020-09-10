/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:19:33 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 00:40:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*array_new(void)
{
	t_array	*array;

	array = ft_xmalloc(sizeof(t_array));
	array->arr = ft_xmalloc(sizeof(char *) * ARRAY_INIT_CAPACITY);
	array->capacity = ARRAY_INIT_CAPACITY;
	array->size = 0;
	return (array);
}
