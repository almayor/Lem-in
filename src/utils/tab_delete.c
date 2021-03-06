/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:59:21 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 00:59:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	tab_delete(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
