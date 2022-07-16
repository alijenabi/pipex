/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:58:36 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Gets the length of the next word from 's' seperated by 'c'
 * @param s[in, out]    The adress of string to be split.
 * @param c[in]         The delimiter character.
 * @return The word length.
 * @note Moves the 's' pointer to the beginning of the word.
 */
static size_t	st_next_word_len(char const **s, char c)
{
	size_t	len;

	len = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[len] && (*s)[len] != c)
	{
		len++;
	}
	return (len);
}

/**
 * Counts the number of words in side the string ('s').
 * @param s[in]	The adress of string to be split.
 * @param c[in]	The delimiter character.
 * @return The number of words in string 's'.
 */
static size_t	st_word_count(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		while (*s && *s != c)
			s++;
		if (*s)
			s++;
	}
	return (count);
}

/** 
 * Splits ’s’, 'count' time using the character ’c’ and puts them in 'ans'.
 * @param ans[in,out] The alocated memory to put the result in it.
 * @param s[in]       The string to be split.
 * @param c[in]       The delimiter character.
 * @param count[in]   The number of world need to be splited
 * @return The array of new strings resulting from the split. NULL if the 
 * 			allocation fails.
 * @note The sole job of this function is to get rid of norminette warning.
 */
static char	**st_split(const char	**ans, char const *s,
					char c, size_t split_count)
{
	char		*current;
	char		**ans_itr;

	ans_itr = (char **)ans;
	while (split_count)
	{
		current = (char *)malloc((st_next_word_len(&s, c) + 1) * sizeof(char));
		if (!current)
			return (0);
		*ans_itr = (char *)current;
		while (*s && *s != c)
			*current++ = *s++;
		*current = '\0';
		ans_itr++;
		split_count--;
	}
	current = 0;
	*ans_itr = 0;
	return ((char **)ans);
}

/** 
 * Allocates (with malloc(3)) and returns an array of strings obtained by 
 * splitting ’s’ using the character ’c’ as a delimiter. The array must end 
 * with a NULL pointer.
 * @param s[in]  The string to be split.
 * @param c[in]  The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the 
 * 			allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	const char	**ans;
	size_t		count;

	if (!s)
		return (NULL);
	count = st_word_count(s, c);
	ans = (const char **)malloc((count + 1) * sizeof(char *));
	if (!ans)
		return (0);
	return (st_split(ans, s, c, count));
}
