/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:01:25 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/23 16:32:12 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reorder_a(t_list **stack_a)
{
	t_list	*lowest;
	int		size;

	lowest = find_lowest(*stack_a);
	size = ft_lstsize(*stack_a);
	if (calcul_position(*stack_a, lowest) <= ((size / 2) + (size % 2)))
	{
		while (lowest->previous != NULL)
			ra(stack_a);
	}
	else
	{
		while (lowest->next != NULL)
			rra(stack_a);
		rra(stack_a);
	}
}

void	push_back(t_list **stack_b, t_list **stack_a)
{
	t_list	*next_highest;
	int		size;

	size = ft_lstsize(*stack_a);
	next_highest = find_next_highest(*stack_b, *stack_a);
	if (calcul_position(*stack_a, next_highest) <= ((size / 2) + (size % 2)))
	{
		while (next_highest->previous != NULL)
			ra(stack_a);
	}
	else
	{
		while (next_highest->next != NULL)
			rra(stack_a);
		rra(stack_a);
	}
	pa(stack_b, stack_a);
}
