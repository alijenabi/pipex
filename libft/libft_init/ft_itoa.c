/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:22:15 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Gets the size of the string required to represent a posetive integer. 
 * @note Negative numbers are handled.
 * @param n[in] The posetive integer to convert.
 * @return The size of string representing n.
 */
static int	st_size(int n)
{
	const int	is_negative = n < 0;
	int			count;

	count = 0;
	if (is_negative)
		n = -n;
	while (n)
	{
		n = n / 10;
		count++;
	}
	if (count == 0)
		return (1);
	return (count + is_negative);
}

/**
 * Gets the power of a value.
 * @param base[in]  The base value.
 * @param power[in] The power value.
 * @return the base powered by power.
 */
static int	st_pow(int base, int power)
{
	int	ans;

	ans = 1;
	if (power == 0)
		return (1);
	while (power--)
		ans *= base;
	return (ans);
}

/**
 * Allocates (with malloc(3)) and returns a string representing a positive 
 * integer received as an argument. 
 * @note Negative numbers are not handled and behaviour is undefined.
 * @param n[in] The positive integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
static char	*st_itop(int n)
{
	char	*ans;
	char	*itr;
	int		base;
	int		size;

	size = st_size(n);
	ans = (char *)malloc((size + 1) * sizeof(char));
	if (!ans)
		return (0);
	itr = (char *)ans;
	if (n < 0)
	{
		n = -n;
		*(itr++) = '-';
		size--;
	}
	while (size--)
	{
		base = st_pow(10, size);
		*itr = (n / base) + '0';
		n -= (n / base) * base;
		itr++;
	}
	*itr = '\0';
	return ((char *)ans);
}

/**
 * Allocates (with malloc(3)) and returns a string representing the integer 
 * received as an argument. 
 * @note Negative numbers are handled.
 * @param n[in] The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	const char	*min = "-2147483648";
	char		*ans;

	if (n == -2147483648)
	{
		ans = (char *)malloc((12) * sizeof(char));
		if (!ans)
			return (0);
		ft_strlcpy(ans, min, 12);
		return (ans);
	}
	return (st_itop(n));
}
