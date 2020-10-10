/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:23:45 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 13:38:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_print(const t_list *list)
{
	t_link	*link;

	link = list->head;
	while (link)
	{
		ft_printf("%i", link->content);
		if (link->next)
			ft_printf(" -> ");
		link = link->next;
	}
	ft_printf("\n");
}
