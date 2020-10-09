/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_sink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 05:22:38 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:43:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_sink(t_min_pq *pq, size_t k)
{
	size_t	j;

	while (2 * k <= pq->size)
	{
		j = 2 * k;
		if (j < pq->size && pq->vals[pq->pq[j]] > pq->vals[pq->pq[j + 1]])
			j++;
		if (pq->vals[pq->pq[j]] < pq->vals[pq->pq[k]])
			min_pq_swap(pq, k, j);
		k = j;
	}
}
