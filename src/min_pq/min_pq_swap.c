/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 05:03:28 by unite             #+#    #+#             */
/*   Updated: 2020/09/18 05:21:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

static void	swap(int *arr, size_t i, size_t j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void		min_pq_swap(t_min_pq *pq, size_t i, size_t j)
{
	swap(pq->pq, i, j);
	swap(pq->qp, pq->pq[i], pq->pq[j]);
}
