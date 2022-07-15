/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:36:06 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 23:41:37 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair_operation.h"
#include "stack_operation.h"
#include "../log/logger.h"

/**
 * @brief Shifts up all elements of the stack a by 1.
 * The first element becomes the last one.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	rotate_a(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|rotate_b(1)", "Rotating a.");
	return (rotate(&(pair->a)));
}

/**
 * @brief Shifts up all elements of the stack b by 1.
 * The first element becomes the last one.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	rotate_b(t_stack_pair *pair)
{
	log_in(INFO, "stack_pair|rotate_b(1)", "Rotating b.");
	return (rotate(&(pair->b)));
}

/**
 * @brief Shifts up all elements of the stack a and b by 1.
 * The first elements becomes the last ones.
 * 
 * @param pair The stack pair.
 * @return 1 if successful, 0 otherwise.
 */
int	rotate_both(t_stack_pair *pair)
{
	return (rotate_a(pair) && rotate_b(pair));
}
