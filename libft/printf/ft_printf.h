/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:40:44 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/23 00:14:11 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

/**
 * @brief Prints a formated string to stdout, according to format and other 
 * 		  arguments passed to it. 
 * @param string[in] Formated string.
 * @param ... [in]   List of arguments to relace the formated string parts 
 *                   with them.
 * @return The number of successfuly printed string to the stdout.
 */
int		ft_printf(const char *string, ...);

#endif