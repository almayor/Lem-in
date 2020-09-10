/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:01:50 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:52:03 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.h"

void	iterator_delete(t_iterator *iter)
{
	free(iter);
}