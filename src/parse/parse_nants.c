/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:02:05 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 12:52:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfgnl.h"
#include "stdin.h"
#include "utils.h"

int	parse_nants(t_stdin *in)
{
	if (!is_nants(stdin_next(in)))
		terminate(ERR_INVALID_INPUT);
	return (ft_atoi(stdin_peek(in)));
}
