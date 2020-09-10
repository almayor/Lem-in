/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:42:02 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 00:01:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdin.h"

char	*stdin_next(t_stdin *in)
{
	int	rc;

	if (in->line)
		free(in->line);
	rc = get_next_line(0, &(in->line));
	if (rc < 0)
		terminate(ERR_STDIN);
	else if (rc == 0)
		in->line = NULL;
	else
		ft_putendl(in->line);
	return (in->line);
}
