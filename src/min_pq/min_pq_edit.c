/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 05:11:31 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:42:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_edit(t_min_pq *pq, int i, int val)
{
	int tmp;

	if ((tmp = pq->qp[i]) == 0)
		return ;
	pq->vals[i] = val;
	min_pq_swim(pq, tmp);
	min_pq_sink(pq, tmp);
}
