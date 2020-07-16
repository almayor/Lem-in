/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:51:55 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 02:12:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include <errno.h>
# include "libftprintfgnl.h"

/*
** @struct s_map
** @brief A bidirectional map between integers and strings
** @par Implementation
** Implemented as a linked list
** @var s_map::key
** @brief The integer key
** @var s_map::val
** @brief The string value
** @var s_map::next
** @brief The next link in the linked list.
*/
typedef struct	s_map
{
	int				key;
	char			*val;
	struct s_map	*next;
}				t_map;

/*
** Allocates memory and initialies a map.
** @return Pointer to the newly allocated memory or `NULL` on failure
** @exception ENOMEM	Memory allocation error
*/
t_map			*make_map(void);

/*
** Insert a key-value pair into the map or update an existing entry if the key
** already exists in the map. A defensive copy of the value string is taken.
** @param map The map
** @param key The key
** @param val The value
** @return 0 on success, 1 on failure
** @exception ENOMEM	Memory allocation error
*/
int				insert_map(t_map *map, int key, const char *val);

/*
** Returns the key associated with a given value.
** @param map The map
** @param val The value
** @return The key associated with the value string.
** @exception EINVAL The value isn't in the map.
*/ 
int				val2key_map(t_map *map, const char *val);

/*
** Returns the value associated with a given key.
** @param map The map
** @param key The key
** @return The value string or `NULL` if the key is not registered in the map.
** @exception EINVAL The key isn't in the map.
*/
char			*key2val_map(t_map *map, int key);

/*
** Frees all memory taken by the map or does nothing if the map is `NULL`.
** @param map The map
*/
void			free_map(t_map *map);

#endif
