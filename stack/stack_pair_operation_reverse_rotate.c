/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation_reverse_rotate.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:47:34 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 23:41:16 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair_operation.h"
#include "stack_operation.h"
#include "../log/logger.h"

/**
 * @brief Shifts down all elements of the stack a by 1.
 * The last element becomes the first one.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	reverse_rotate_a(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|reverse_rotate_b(1)", "Reverse rotating a.");
	return (reverse_rotate(&(pair->a)));
}

/**
 * @brief Shifts down all elements of the stack b by 1.
 * The last element becomes the first one.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	reverse_rotate_b(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|reverse_rotate_b(1)", "Reverse rotating b.");
	return (reverse_rotate(&(pair->b)));
}

/**
 * @brief Shifts down all elements of the stack a and b by 1.
 * The last elements becomes the first ones.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	reverse_rotate_both(t_stack_pair *pair)
{
	return (reverse_rotate_a(pair) && reverse_rotate_b(pair));
}
