/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:35:43 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 22:49:05 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair_operation.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Gives all of the statck operations as function pointers.
 * The length of the return value is STACK_PAIR_OPERATION_COUNT.
 * 
 * @return The function pointer fo all of the stack operations.
 */
stack_pair_operation	*posible_stack_pair_operations(void)
{
	static stack_pair_operation	*operations = 0;

	if (!operations)
	{
		operations = malloc(
				STACK_PAIR_OPERATION_COUNT * sizeof(stack_pair_operation));
		if (!operations)
			log_in(ERROR, "stack|posible_stack_pair_operations(0)",
				"Cannot allocate memory.");
			operations[0] = &swap_a;
			operations[1] = &swap_b;
			operations[2] = &swap_both;
			operations[3] = &push_a;
			operations[4] = &push_b;
			operations[5] = &rotate_a;
			operations[6] = &rotate_b;
			operations[7] = &rotate_both;
			operations[8] = &reverse_rotate_a;
			operations[9] = &reverse_rotate_b;
			operations[10] = &reverse_rotate_both;
	}
	return (operations);
}

void	print_pair_operation(stack_pair_operation operation)
{
	if (operation == posible_stack_pair_operations()[0])
		ft_printf("sa\n");
	if (operation == posible_stack_pair_operations()[1])
		ft_printf("sb\n");
	if (operation == posible_stack_pair_operations()[2])
		ft_printf("ss\n");
	if (operation == posible_stack_pair_operations()[3])
		ft_printf("pa\n");
	if (operation == posible_stack_pair_operations()[4])
		ft_printf("pb\n");
	if (operation == posible_stack_pair_operations()[5])
		ft_printf("ra\n");
	if (operation == posible_stack_pair_operations()[6])
		ft_printf("rb\n");
	if (operation == posible_stack_pair_operations()[7])
		ft_printf("rr\n");
	if (operation == posible_stack_pair_operations()[8])
		ft_printf("rra\n");
	if (operation == posible_stack_pair_operations()[9])
		ft_printf("rrb\n");
	if (operation == posible_stack_pair_operations()[10])
		ft_printf("rrr\n");
}
