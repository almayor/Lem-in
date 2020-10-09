/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:05:40 by user              #+#    #+#             */
/*   Updated: 2020/10/09 23:07:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"
#include <stdio.h>

int main(void)
{
	t_min_pq	*pq = min_pq_new(10);
	min_pq_add(pq, 1, 100);
	min_pq_add(pq, 2, 50);
	printf("%i\n", min_pq_pop(pq));
	min_pq_add(pq, 3, 70);
	min_pq_add(pq, 4, 300);
	min_pq_add(pq, 5, 0);
	min_pq_edit(pq, 4, 1);
	min_pq_edit(pq, 5, 71);
	printf("%i\n", min_pq_pop(pq));
	min_pq_edit(pq, 1, 400);
	printf("%i\n", min_pq_pop(pq));
	printf("%i\n", min_pq_pop(pq));
	printf("%i\n", min_pq_pop(pq));
	min_pq_delete(pq);
}
