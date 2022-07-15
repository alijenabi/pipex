/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation_swap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:20:11 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 23:42:03 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair_operation.h"
#include "stack_operation.h"
#include "../log/logger.h"

/**
 * @brief Swaps the first 2 elements at the top of the stack a.
 * Does noting if there is only one or no element is in a.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	swap_a(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|swap_a(1)", "Swapping a.");
	return (swap(&(pair->a)));
}

/**
 * @brief Swaps the first 2 elements at the top of the stack b.
 * Does noting if there is only one or no element is in b.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 * 
 */
int	swap_b(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|swap_b(1)", "Swapping b.");
	return (swap(&(pair->b)));
}

/**
 * @brief Swaps the first 2 elements at the top of both stack a and b.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	swap_both(t_stack_pair *pair)
{
	return (swap_a(pair) && swap_b(pair));
}
