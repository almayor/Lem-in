/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 01:53:42 by unite             #+#    #+#             */
/*   Updated: 2020/10/09 23:42:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_delete(t_min_pq *pq)
{
	free(pq->vals);
	free(pq->pq);
	free(pq->qp);
	free(pq);
}
