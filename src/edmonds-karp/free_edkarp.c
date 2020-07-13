/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_edkarp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:06:55 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 21:32:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edmonds-karp.h"

void free_edkarp(t_edkarp *edkarp)
{
	if (!edkarp)
		return ;
	free(edkarp->marked);
	free(edkarp->edge_to);
	free(edkarp->dist_to);
	free(edkarp);
}
