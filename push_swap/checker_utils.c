/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:59 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/26 18:00:29 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_check(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rr_check(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}

void	rrr_check(t_list **pile_a, t_list **pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
}

void	push_check(t_list **stack_b, t_list **stack_a)
{
	if (*stack_b && ((*stack_b)->next == NULL && (*stack_b)->previous == NULL))
	{
		(*stack_b)->next = *stack_a;
		(*stack_a)->previous = *stack_b;
		*stack_a = *stack_b;
		*stack_b = NULL;
	}
	else
		push(stack_b, stack_a);
}

int	bonordre_check(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
