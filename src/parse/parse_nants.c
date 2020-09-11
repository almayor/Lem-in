/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:02:05 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 16:14:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfgnl.h"
#include "stdin.h"
#include "utils.h"

int	parse_nants(t_stdin *in)
{
	int	nants;

	if (!is_nants(stdin_next(in)))
		terminate(ERR_INVALID_INPUT);
	nants = ft_atoi(stdin_peek(in));
	if (nants < 0)
		terminate(ERR_INVALID_INPUT);
	return (nants);
}
