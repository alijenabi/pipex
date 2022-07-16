/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:07:19 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/24 21:57:17 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPERS_H
# define FT_PRINTF_HELPERS_H
# include <stdarg.h>

/**
 * @brief Prints a single character to the stdout.
 * 
 * @param c[in]          The conversision character for char ('c').
 * @param list[in, out]  The list of parameters.
 * @return The size of the printed string (if any) to stdout.
 * @note Only prints if c == 'c'.
 * @note Only the first item on list will be used.
 */
int		ft_printf_if_char(const char c, va_list *list);

/**
 * @brief Prints (null) to the stdout if recives NULL pointer.
 * 
 * @param list[in, out]  The list of parameters.
 * @return The size of the printed string (if any) to stdout.
 * @note Only the first item on list will be used.
 */
int		ft_printf_if_null(void *list);

/**
 * @brief Prints a number to the stdout.
 * Possible conversision character: 
 *    i: integer,
 *    d: decimal,
 *    u: unsigned decimal,
 *    x: number in hexadecimal in lowercase,
 *    X: number in hexadecimal in uppercase.
 * 
 * @param c[in]          The conversision character for number.
 * @param list[in, out]  The list of parameters.
 * @return The size of the printed string (if any) to stdout.
 * @note Only the first item on list will be used.
 */
int		ft_printf_if_number(const char c, va_list *list);

/**
 * @brief Prints a pointer address to the stdout.
 * 
 * @param c[in]          The conversision character for pointer ('p').
 * @param list[in, out]  The list of parameters.
 * @return The size of the printed string (if any) to stdout.
 * @note Only prints if c == 'p'.
 * @note Only the first item on list will be used.
 */
int		ft_printf_if_pointer(const char c, va_list *list);

/**
 * @brief Prints a string to the stdout.
 * 
 * @param c[in]          The conversision character for string ('s').
 * @param list[in, out]  The list of parameter.
 * @return The size of the printed string (if any) to stdout.
 * @note Only prints if c == 's'.
 * @note Only the first item on list will be used.
 */
int		ft_printf_if_string(const char c, va_list *list);

#endif
