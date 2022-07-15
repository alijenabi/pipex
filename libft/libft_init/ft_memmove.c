/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:12:13 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <string.h>

/**
 * Copies n bytes from memory area src to memory area dest. The memory areas 
 * may overlap.
 * @note Overlap means that the src and dest are pointing to the same string 
 *       and src will be changed during the proces.
 * @param dst[out] The destination string.
 * @param src[in]  The source string.
 * @param len[in]  The size of the characters to copy from src to dst.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((char *)dst)[len] = ((char *)src)[len];
	return (dst);
}
