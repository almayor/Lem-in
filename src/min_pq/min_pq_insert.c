/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 00:10:15 by user              #+#    #+#             */
/*   Updated: 2020/10/10 00:10:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void		min_pq_insert(t_min_pq *pq, int i, int val)
{
	if (min_pq_contains(pq, i))
		min_pq_edit(pq, i, val);
	else
		min_pq_add(pq, i, val);
}
