/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:29:35 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 00:09:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <stdlib.h>
# include "libftprintfgnl.h"

/*
** Mirrors the behaviour of `calloc` but terminates if memory allocation
** fails
*/

void	*ft_xcalloc(size_t count, size_t size);

/*
** Mirrors the behaviour of `malloc` but terminates if memory allocation
** fails
*/

void	*ft_xmalloc(size_t size);

/*
** Checks if the given string is a comment
** @return `1` if it's a comment, `0` otherwise
*/

int		is_comment(const char *s);

/*
** Checks if the given string is a room coordinate
** @return `1` if it's a room coordinate, `0` otherwise
*/

int		is_coord(const char *s);

/*
** Checks if the given string is the `##end` command
** @return `1` if it's the `##end` command, `0` otherwise
*/

int		is_end(const char *s);

/*
** Checks if the given string represents a link between two rooms
** @return `1` if it represents a link, `0` otherwise
*/

int		is_link(const char *s);

/*
** Checks if the given string specifies the number of ants
** @return `1` if it specifies the number of ants, `0` otherwise
*/

int		is_nants(const char *s);

/*
** Checks if the given string is the name of a room
** @return `1` if it is the name of a room, `0` otherwise
*/
int		is_room(const char *s);

/*
** Checks if the given string is the `##start` command
** @return `1` if it's the `##start` command, `0` otherwise
*/

int		is_start(const char *s);

/*
** Frees all memory taken up by a `NULL`-terminated tab of strings
*/

void	tab_delete(char **tab);

/*
** Computes the number of entries in `NULL`-terminated tab of strings
** @return The number of entries in the tab
*/

size_t	tab_len(char **tab);

/*
** Prints a message to `STDERR` end exits
** @param mes The message to print to `STDERR`
*/

void	terminate(const char *mes);

# define ERR_NO_MEMORY	"Memory allocation error"
# define ERR_INVALID_INPUT	"ERROR"
# define ERR_STDIN	"Couldn't read from STDIN"

#endif
