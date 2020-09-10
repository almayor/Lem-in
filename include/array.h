/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:28:04 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 12:08:02 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H

# define ARRAY_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

# define ARRAY_INIT_CAPACITY	4

typedef struct	s_array
{
	size_t			size;
	size_t			capacity;
	char			**arr;
}				t_array;

void			array_append(t_array *array, char *val);
void			array_delete(t_array *array);
char			*array_get(const t_array *array, int index);
void			array_grow(t_array *array);
int				array_indexof(const t_array *array, const char *val);
void			array_insertion_sort(t_array *array);
t_array			*array_new(void);
void			array_quick_sort(t_array *array);
void			array_shrink(t_array *array);
int				array_size(const t_array *array);
void			array_swap(t_array *array, int ind1, int ind2);

#endif
