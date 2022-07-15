/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:07:34 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/10 17:43:06 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Adds the top element of the source to the target.
 * This function is solely exist to satisfy the norm.
 * 
 * @param source The source stack.
 * @param target The target stack.
 */
static void	st_add(t_stack *source, t_stack *target);

/**
 * @brief Removes one elemnt form the source.
 * This function is solely exist to satisfy the norm.
 * 
 * @param source The push source.
 */
static void	st_remove(t_stack *source);

/**
 * @brief Pushies the frist element of the "from stack" to the "to stack".
 * This function is moved to this file to satisfy the norm.
 * 
 * @param source The source stack.
 * @param target The target stack.
 * @return 1 if successful, 0 otherwise.
 */
int	push(t_stack *source, t_stack *target)
{
	if (source->length)
	{
		st_add(source, target);
		st_remove(source);
		return (1);
	}
	return (0);
}

static void	st_add(t_stack *source, t_stack *target)
{
	t_stack_element	*temp;
	int				itr;

	(target->length)++;
	temp = malloc(target->length * sizeof(t_stack_element));
	if (!temp)
		log_in(ERROR, "stack|operation|push(2)",
			"Cannot allocate memory for target.");
	temp[0] = source->elements[0];
	itr = 1;
	while (itr < target->length)
	{
		temp[itr].value = target->elements[itr - 1].value;
		itr++;
	}
	free(target->elements);
	target->elements = temp;
}

static void	st_remove(t_stack *source)
{
	t_stack_element	*temp;
	int				itr;

	(source->length)--;
	if (source->length)
	{
		temp = malloc(source->length * sizeof(t_stack_element));
		if (!temp)
			log_in(ERROR, "stack|operation|push(2)",
				"Cannot allocate memory for source.");
		itr = 0;
		while (itr < source->length)
		{
			temp[itr].value = source->elements[itr + 1].value;
			itr++;
		}
		free(source->elements);
		source->elements = temp;
	}
	else
	{
		free(source->elements);
		source->elements = 0;
	}
}
