/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:29:35 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 02:21:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <stdlib.h>
# include "libftprintfgnl.h"

void	*ft_xcalloc(size_t count, size_t size);
void	*ft_xmalloc(size_t size);
int		is_comment(const char *line);
int		is_coord(const char *line);
int		is_end(const char *line);
int		is_link(const char *line);
int		is_nants(const char *line);
int		is_room(const char *line);
int		is_start(const char *line);
void	tab_delete(char **tab);
size_t	tab_len(char **tab);
void	terminate(const char *mes);

# define ERR_NO_MEMORY	"Memory allocation error"
# define ERR_INVALID_INPUT	"ERROR"
# define ERR_STDIN	"Couldn't read from STDIN"

#endif
