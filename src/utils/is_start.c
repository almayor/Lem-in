/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:16:01 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 02:20:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_start(const char *s)
{
	return (ft_strequ(s, "##start"));
}