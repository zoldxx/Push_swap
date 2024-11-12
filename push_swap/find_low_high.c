/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_low_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:58:41 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/23 14:57:56 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_highest(t_list *stack)
{
	t_list	*highest;

	highest = stack;
	while (stack)
	{
		if (highest->nb < stack->nb)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_list	*find_lowest(t_list *stack)
{
	t_list	*lowest;

	lowest = stack;
	while (stack)
	{
		if (lowest->nb > stack->nb)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

t_list	*find_next_lowest(t_list *stack_a, t_list *stack_b)
{
	t_list	*next_lowest;
	t_list	*tmp_b;

	tmp_b = stack_b;
	if (stack_a->nb > find_highest(stack_b)->nb)
		return (find_highest(stack_b));
	if (stack_a->nb < find_lowest(stack_b)->nb)
		return (find_highest(stack_b));
	while (stack_a->nb < stack_b->nb)
	{
		stack_b = stack_b->next;
		if (stack_b == NULL)
			return (tmp_b);
	}
	next_lowest = stack_b;
	while (stack_b)
	{
		if (stack_a->nb > stack_b->nb && stack_b->nb > next_lowest->nb)
			next_lowest = stack_b;
		stack_b = stack_b->next;
	}
	return (next_lowest);
}

t_list	*find_next_highest(t_list *stack_b, t_list *stack_a)
{
	t_list	*next_highest;
	t_list	*tmp_a;

	tmp_a = stack_a;
	if (stack_b->nb > find_highest(stack_a)->nb
		|| stack_b->nb < find_lowest(stack_a)->nb)
		return (find_lowest(stack_a));
	while (stack_b->nb > stack_a->nb)
	{
		stack_a = stack_a->next;
		if (stack_a == NULL)
			return (tmp_a);
	}
	next_highest = stack_a;
	while (stack_a)
	{
		if (stack_b->nb < stack_a->nb && stack_a->nb < next_highest->nb)
			next_highest = stack_a;
		stack_a = stack_a->next;
	}
	return (next_highest);
}
