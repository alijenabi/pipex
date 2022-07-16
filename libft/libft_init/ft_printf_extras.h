/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:04:56 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:30:41 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_EXTRAS_H
# define FT_PRINTF_EXTRAS_H

/**
 * @brief Converts all the character of a sting to lowercase characters.
 * @note It will not touch the non-alphabetic characters.
 * 
 * @param str[in, out] The string to lowercase.
 * @return The lowercased string.
 */
char	*ft_str_tolower(char *str);

/**
 * @brief Converts all the character of a sting to uppercase characters.
 * @note It will not touch the non-alphabetic characters.
 * 
 * @param str[in, out] The string to uppercase.
 * @return The uppercased string.
 */
char	*ft_str_toupper(char *str);

/**
 * @brief Inverses a string and returns it.
 * 
 * @param str[in, out] The string to inverse
 * @return The inversed string.
 */
char	*ft_strinv(char *str);

/**
 * @brief Converts an unsigned integer to its string representation on any 
 *        bases between 2 and 36. 
 * 
 * @param number The number to convert.
 * @param base   The base.
 * @return The string representation of the number in the base.
 */
char	*ft_ulong_to_str(unsigned long number, unsigned long base);

#endif
