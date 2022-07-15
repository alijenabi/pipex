/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:21:14 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 13:02:30 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"
#include "../libft.h"
#include <stdarg.h>

int	ft_printf_if_string(const char c, va_list *list)
{
	void	*ptr;
	int		is_null;

	if (c == 's')
	{
		ptr = va_arg(*list, void *);
		is_null = ft_printf_if_null(ptr);
		if (is_null)
			return (is_null);
		ft_putstr_fd((char *)ptr, 1);
		return (ft_strlen((char *)ptr));
	}
	return (0);
}
