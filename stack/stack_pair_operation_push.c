/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation_push.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:36:06 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/07 22:27:14 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair_operation.h"
#include "stack_operation.h"
#include "../log/logger.h"

/**
 * @brief Thakes the first element a the top of the stack b and puts it at the 
 * top of stack a.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	push_a(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|swap_a(1)", "Pushing from b to a.");
	return (push(&(pair->b), &(pair->a)));
}

/**
 * @brief Thakes the first element a the top of the stack a and puts it at the 
 * top of stack b.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	push_b(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|swap_a(1)", "Pushing from a to b.");
	return (push(&(pair->a), &(pair->b)));
}
