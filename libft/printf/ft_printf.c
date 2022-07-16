/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:40:50 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 13:02:36 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

/**
 * @brief Prints next list item to the stdout.
 * 
 * @param c[in]          The conversision character for the next item in list.
 * @param list[in, out]  The list of parameters.
 * @return The size of the printed string (if any) to stdout.
 */
static int	st_printf_item(const char c, va_list *list);

/**
 * @brief Prints the character to the stdout if it is '%'.
 * 
 * @param c[in] the character.
 * @return Number of characters (if any) that are printed to the stdout.
 */
static int	st_printf_if_const(const char c);

int	ft_printf(const char *string, ...)
{
	va_list	list;
	char	*itr;
	size_t	ans;

	va_start(list, string);
	itr = (char *)string;
	ans = 0;
	while (*itr)
	{
		if (*itr == '%' && *(itr + 1) && ft_strchr("cspdiuxX%", *(itr + 1)))
		{
			ans += st_printf_item(*(itr + 1), &list);
			itr += 2;
		}
		else
		{
			ans += write(1, itr, 1);
			itr++;
		}
	}
	va_end(list);
	return (ans);
}

static int	st_printf_item(const char c, va_list *list)
{
	int	count;

	count = ft_printf_if_char(c, list);
	count += ft_printf_if_string(c, list);
	count += ft_printf_if_pointer(c, list);
	count += ft_printf_if_number(c, list);
	count += st_printf_if_const(c);
	return (count);
}

static int	st_printf_if_const(const char c)
{
	if (c == '%')
		return (write(1, &c, 1));
	return (0);
}
