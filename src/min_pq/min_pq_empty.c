/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:55:54 by user              #+#    #+#             */
/*   Updated: 2020/10/09 23:42:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_empty(t_min_pq *pq)
{
	ft_bzero(pq->vals, sizeof(int) * (pq->size + 1));
	ft_bzero(pq->pq, sizeof(int) * (pq->size + 1));
	ft_bzero(pq->qp, sizeof(int) * (pq->size + 1));
}
