/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:26:02 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * The calloc() function allocates memory for an array of nmemb elements of size
 * bytes each and returns a pointer to the allocated memory. The memory is set 
 * to zero. If nmemb or size is 0, then calloc() returns either NULL.
 * @param count[in] The array element count.
 * @param size[in]  The memory size of each element of the array.
 * @return The pointer to the firs element of the array.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*itr;
	size_t	result_size;

	result_size = count * size;
	if (!count || !size
		|| result_size / count != size || result_size / size != count)
		return (NULL);
	itr = malloc(result_size);
	if (!itr)
		return (NULL);
	ft_bzero(itr, result_size);
	return (itr);
}
