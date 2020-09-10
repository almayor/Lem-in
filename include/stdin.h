/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 01:19:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_H

# define STDIN_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

/*
** @struct s_stdin
** @brief A convenience data type for reading from `STDIN`
*/

typedef struct		s_stdin
{
	char	*line;
}					t_stdin;

/*
** Frees all memory taken up by `t_stdin`
*/

void			stdin_delete(t_stdin *in);

/*
** Initializes a new `t_stdin`
** @returns A new `t_stdin`
*/

t_stdin			*stdin_new(void);

/*
** Reads the next line `STDIN` and returns it
** @return The next line in the `STDIN`
** @note As per the assignment, this function re-prints everything that it reads
** to `STDOUT`
*/

char			*stdin_next(t_stdin *in);

/*
** Returns the line that was most recently read from the `STDIN`
** @return The line that was most recently read from the `STDIN`
*/

char			*stdin_peek(t_stdin *in);

#endif
