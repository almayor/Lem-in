/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:05:12 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:42:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void		min_pq_add(t_min_pq *pq, int i, int val)
{
	pq->size++;
	pq->qp[i] = pq->size;
	pq->pq[pq->size] = i;
	pq->vals[i] = val;
	min_pq_swim(pq, pq->size);
}
