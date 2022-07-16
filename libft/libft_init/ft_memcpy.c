/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:54 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 13:45:46 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Copies n bytes from memory area src to memory area dest. The memory areas 
 * must not overlap. Use ft_memmove(3) if the memory areas do overlap.
 * @note Overlap means that the src and dest are pointing to the same string 
 *       and src will be changed during the proces.
 * @param dst[out] The destination string.
 * @param src[in]  The source string.
 * @param n[in]    The size of the characters to copy from src to dst.
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*itr;

	itr = dst;
	while (n && src)
	{
		*(char *)itr = *(char *)src;
		itr++;
		src++;
		n--;
	}
	return (dst);
}
