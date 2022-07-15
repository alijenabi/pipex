/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:11:31 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 23:20:07 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Duplicates the stack pair.
 * It allocates memory for the stack member array.
 * 
 * @param pair The stack pair.
 * @return The duplicated stack pair.
 */
t_stack_pair	*duplicate_stack_pair(t_stack_pair pair)
{
	t_stack_pair	*new_pair;

	new_pair = malloc(sizeof(t_stack_pair));
	if (!new_pair)
		log_in(ERROR, "stack|duplicate_stack_pair(1)", "Cannot allocate memory.");
	new_pair->a = duplicate_stack(pair.a);
	new_pair->b = duplicate_stack(pair.b);
	return (new_pair);
}

/**
 * @brief Destroyes the stack pair by freeing the memeory of its stacks' 
 *        elements.
 * 
 * @param pair The stack pair.
 */
void	destroy_stack_pair(t_stack_pair *pair)
{
	destroy_stack(pair->a);
	destroy_stack(pair->b);
	free(pair);
}

/**
 * @brief Checks if the stack pair is sorted.
 * If there is any element in stack b, the stack pair is considered not sorted.
 * 
 * @param pair The stack pair.
 * @return 1 if the stack pair is sorted, 0 otherwise.
 */
int	is_stack_pair_sorted(t_stack_pair pair)
{
	return (pair.b.length == 0 && is_stack_sorted(pair.a));
}

/**
 * @brief Generates the stack pair from the raw info.
 * 
 * @param length    The length of the a stack of the stack pair.
 * @param elements  The stack a's elements in staring.
 * @return The stack pair.
 */
t_stack_pair	generate_stack_pair(const int length, char *const *elements)
{
	t_stack_pair	pair;

	pair.a = generate_stack(length, elements);
	pair.b = generate_stack(0, NULL);
	return (pair);
}

/**
 * @brief Prints the stack pair to stdout.
 * 
 * @param pair The stack pair.
 */
void	print_stack_pair(t_stack_pair *pair)
{
	ft_printf("a | ");
	print_stack(&(pair->a));
	ft_printf("b | ");
	print_stack(&(pair->b));
}
