/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:56:20 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 02:21:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int is_link(const char *s)
{
	char	**tab;
	int		ret;

	if (!(tab = ft_strsplit(s, '-')))
		terminate(ERR_NO_MEMORY);
	ret = tab_len(tab) == 2 && is_room(tab[0]) && is_room(tab[1]);
	tab_delete(tab);
	return (ret);
}
