/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:11:46 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 13:02:02 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

int	ft_printf_if_char(const char c, va_list *list)
{
	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(*list, int), 1);
		return (1);
	}
	return (0);
}
