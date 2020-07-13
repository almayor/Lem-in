/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:23:45 by unite             #+#    #+#             */
/*   Updated: 2020/07/13 20:31:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*add_list(t_list *list, int val)
{
	t_list	*new_link;

	if (!(new_link = ft_calloc(sizeof(t_list), 1)))
		return (NULL);
	new_link->val = val;
	new_link->next = list;
	return (new_link);
}
