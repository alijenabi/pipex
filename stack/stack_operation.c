/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:04:39 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/07 17:15:58 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Swaps the first 2 elements at the top of the stack.
 * 
 * @param stack The stack.
 * @return 1 if successful, 0 otherwise.
 */
int	swap(t_stack *stack)
{
	t_stack_element	temp;

	if (stack->length > 1)
	{
		temp = stack->elements[0];
		stack->elements[0] = stack->elements[1];
		stack->elements[1] = temp;
		return (1);
	}
	return (0);
}

/**
 * @brief Shifts up all elements of the stack by 1.
 * The firstt element becomes the last one.
 * 
 * @param stack The stack.
 * @return 1 if successful, 0 otherwise.
 */
int	rotate(t_stack *stack)
{
	t_stack_element	temp;
	int				itr;

	if (stack->length > 1)
	{
		itr = 1;
		temp = stack->elements[0];
		while (itr < stack->length)
		{
			stack->elements[itr - 1] = stack->elements[itr];
			itr++;
		}
		stack->elements[itr - 1] = temp;
		return (1);
	}
	return (0);
}

/**
 * @brief Shifts down all elements of the stack by 1.
 * The last element becomes the first one.
 * 
 * @param stack The stack.
 * @return 1 if successful, 0 otherwise.
 */
int	reverse_rotate(t_stack *stack)
{
	t_stack_element	temp;
	int				itr;

	if (stack->length > 1)
	{
		temp = stack->elements[stack->length - 1];
		itr = stack->length - 1;
		while (itr > 0)
		{
			stack->elements[itr] = stack->elements[itr - 1];
			itr--;
		}
		stack->elements[0] = temp;
		return (1);
	}
	return (0);
}
