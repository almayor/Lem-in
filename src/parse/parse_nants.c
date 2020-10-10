/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:02:05 by unite             #+#    #+#             */
/*   Updated: 2020/10/10 21:12:03 by user             ###   ########.fr       */
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
