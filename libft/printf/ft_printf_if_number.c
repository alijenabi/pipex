/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:47:00 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 13:02:11 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf_if_number(const char c, va_list *list)
{	
	char	*string;
	int		ans;

	string = NULL;
	if (c == 'd' || c == 'i')
		string = ft_itoa(va_arg(*list, int));
	if (c == 'u')
		string = ft_ulong_to_str(va_arg(*list, unsigned int), 10);
	if (c == 'x')
		string = ft_str_tolower(
				ft_ulong_to_str(va_arg(*list, unsigned int), 16));
	if (c == 'X')
		string = ft_str_toupper(
				ft_ulong_to_str(va_arg(*list, unsigned int), 16));
	if (string)
	{
		ft_putstr_fd(string, 1);
		ans = ft_strlen(string);
		free(string);
		return (ans);
	}
	return (0);
}
