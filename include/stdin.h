/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 00:39:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_H

# define STDIN_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

typedef struct		s_stdin
{
	char	*line;
}					t_stdin;

void				stdin_delete(t_stdin *in);
t_stdin				*stdin_new(void);
char				*stdin_next(t_stdin *in);
char				*stdin_peek(t_stdin *in);

#endif
