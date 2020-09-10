/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:28:04 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 00:43:53 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H

# define ARRAY_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "utils.h"

/*
** The initial capacity of an array. 
** @remark Change this if you know that the array will contain many more items
** on average.
*/

# define ARRAY_INIT_CAPACITY	4

/*
** @struct s_array
** @brief A resizable array of strings
** @details The array will double in size when its capacity is filled,
** and halve its size when only `1/4` of its capacity is used.
** @var s_array::size
** @brief The number of items in this array
** @var s_array::capacity
** @brief The capacity of this array
** @var s_array::arr
** @brief The data
*/

typedef struct	s_array
{
	size_t			size;
	size_t			capacity;
	char			**arr;
}				t_array;

/*
** Appends a value at the end of this array.
** @param content	The value
*/

void			array_append(t_array *array, char *val);

/*
** Deletes the array and all its associated data
*/

void			array_delete(t_array *array);

/*
** Returns the value at the specified position in this list.
** @return The value
** @param index	The index (0-based counting)
*/

char			*array_get(const t_array *array, size_t index);

/*
** Doubles the capacity of the array by reallocating and copying its contents
*/

void			array_grow(t_array *array);

/*
** Returns the index of a specified value in the array
** @note This function ONLY works if the array has been pre-sorted. If this
** isn't the case, the function may fail.
** @remark This function uses binary search and has complexity `O(logE)`
** @param val The value to search for
** @return The index
*/

size_t			array_indexof(const t_array *array, const char *val);

/*
** Sorts the array using insertion sort
*/

void			array_insertion_sort(t_array *array);

/*
** Allocates memory and returns an empty array of capacity `ARRAY_INIT_CAPACITY`
** @return An empty array
*/

t_array			*array_new(void);

/*
** Sorts the array using quick sort
** @remark This function defaults to `array_insertion_sort` if the number of
** elements in the array is less than or equal to 7
*/

void			array_quick_sort(t_array *array);

/*
** Halves the capacity of the array by reallocating and copying its contents
*/

void			array_shrink(t_array *array);

/*
** Returns the numbers of elements in the array
** @return The size of the array
*/

size_t			array_size(const t_array *array);

/*
** Swaps two elements in the array, which are specified by their indices
** @param ind1 Index of the first element
** @param ind2 Index of the second element
*/

void			array_swap(t_array *array, size_t ind1, size_t ind2);

#endif
