/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_sink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 05:22:38 by unite             #+#    #+#             */
/*   Updated: 2020/09/18 05:23:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_sink(t_min_pq *pq, size_t k)
{
	size_t	j;

	while (2 * k <= pq->size)
	{
		j = 2 * k;
		if (j < pq->size && pq->key[j] < pq->key[k])
			j++;
		if (pq->key[j] < pq->key[k])
			min_pq_swap(pq, k, j);
		k = j;
	}
}
