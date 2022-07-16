/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:34 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 13:02:18 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf_if_pointer(const char c, va_list *list)
{
	char	*string;
	int		len;

	if (c == 'p')
	{
		string = ft_ulong_to_str((unsigned long)va_arg(*list, void *), 16);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(string, 1);
		len = ft_strlen(string) + 2;
		free(string);
		return (len);
	}
	return (0);
}
