/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:02:47 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/07 17:19:41 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATION_H
# define STACK_OPERATION_H
# include "stack.h"

int	swap(t_stack *stack);
int	push(t_stack *source, t_stack *target);
int	rotate(t_stack *stack);
int	reverse_rotate(t_stack *stack);

#endif // STACK_OPERATION_H
