/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 22:06:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_H

# define STDIN_H

# include <stdlib.h>
# include <unistd.h>
# include "libftprintfgnl.h"
# include "utils.h"

# define BUFFER_SIZE	2048

/*
** @struct s_stdin
** @brief A convenience data type for reading from `STDIN`
*/

typedef struct	s_stdin
{
	char	buffer[BUFFER_SIZE + 1];
	char	*ptr;
	char	*line;
	size_t	carryover;
	char	end;
}				t_stdin;

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

const char		*stdin_next(t_stdin *in);

/*
** Returns the line that was most recently read from the `STDIN`
** @return The line that was most recently read from the `STDIN`
*/

const char		*stdin_peek(t_stdin *in);

#endif
