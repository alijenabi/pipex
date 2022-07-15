/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:12:47 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/09 00:55:42 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Checks if the string is numeric or not.
 * 
 * @param str The string.
 * @throw Error if the string is non-numeric.
 */
static void	st_check_str_is_numeric(const char *str)
{
	int	itr;

	itr = 0;
	while (str[itr])
	{
		if (str[itr] != '-' && str[itr] != '+' && !ft_isdigit(str[itr]))
			log_in(ERROR, "stack|generate_stack(2)", "None numeric input!");
		itr++;
	}
}

/**
 * @brief Destroys the stack. Frees the allocated memeory.
 * 
 * @param stack The stack.
 */
void	destroy_stack(t_stack stack)
{
	if (stack.length)
		free(stack.elements);
	stack.length = 0;
}

/**
 * @brief Duplication the stack.
 * @note Allocates memory for the items.
 * 
 * @param stack The stack.
 * @return The duplication resutl.
 */
t_stack	duplicate_stack(t_stack stack)
{
	t_stack	dup_stack;
	int		itr;

	dup_stack.length = stack.length;
	if (dup_stack.length)
	{
		dup_stack.elements = malloc(dup_stack.length * sizeof(t_stack_element));
		if (!stack.elements)
			log_in(ERROR, "stack|duplicate_stack(2)",
				"Cannot allocate memory.");
		itr = 0;
		while (itr < dup_stack.length)
		{
			dup_stack.elements[itr] = stack.elements[itr];
			itr++;
		}
	}
	else
		dup_stack.elements = NULL;
	return (dup_stack);
}

/**
 * @brief Checks if the stack is sorted or not.
 * 
 * @param stack The stack.
 * @return int 
 */
int	is_stack_sorted(const t_stack stack)
{
	int	itr;

	if (stack.length <= 1)
		return (1);
	itr = 1;
	while (itr < stack.length)
	{
		if (stack.elements[itr - 1].value > stack.elements[itr].value)
			return (0);
		itr++;
	}
	return (1);
}

/**
 * @brief Generates the stack.
 * 
 * @param length The length of the stack.
 * @param items The items of the stack.
 * @return The stack.
 * @throw Error if there is an invalid item or cannot alocate memory.
 */
t_stack	generate_stack(const int length, char *const *items)
{
	t_stack	stack;
	int		itr;

	stack.length = length;
	if (length)
	{
		stack.elements = malloc(length * sizeof(t_stack_element));
		if (!stack.elements)
			log_in(ERROR, "stack|generate_stack(2)", "Cannot allocate memory.");
		itr = 0;
		while (itr < length)
		{
			st_check_str_is_numeric(items[itr]);
			stack.elements[itr] = (t_stack_element){.value = ft_atoi(items[itr])};
			itr++;
		}
	}
	else
		stack.elements = NULL;
	return (stack);
}

/**
 * @brief Prints the stack.
 * 
 * @param stack The stack.
 */
void	print_stack(t_stack *stack)
{
	char	*value_str;
	int		itr;

	itr = stack->length;
	while (--itr >= 0)
	{
		value_str = ft_itoa(stack->elements[itr].value);
		write(STDOUT_FILENO, value_str, ft_strlen(value_str));
		free(value_str);
		if (itr != 0)
			write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
