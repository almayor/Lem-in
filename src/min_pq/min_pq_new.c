/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 01:46:17 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:42:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

t_min_pq	*min_pq_new(size_t max_size)
{
	t_min_pq	*pq;

	pq = ft_xcalloc(sizeof(t_min_pq), 1);
	pq->size = 0;
	pq->vals = ft_xcalloc(sizeof(int), max_size + 1);
	pq->pq = ft_xcalloc(sizeof(int), max_size + 1);
	pq->qp = ft_xcalloc(sizeof(int), max_size + 1);
	return (pq);
}
