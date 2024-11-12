/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_moins_de_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:38 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/24 13:28:30 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_2(t_list **stack_a)
{
	if (!bonordre(*stack_a))
		sa(*stack_a);
}

void	tri_3(t_list **stack_a)
{
	while (!bonordre(*stack_a))
	{
		if ((*stack_a)->nb < (*stack_a)->next->next->nb
			&& (*stack_a)->next->nb > (*stack_a)->next->next->nb)
		{
			rra(stack_a);
			sa(*stack_a);
		}
		else if ((*stack_a)->nb > (*stack_a)->next->nb
			&& (*stack_a)->nb < (*stack_a)->next->next->nb)
			sa(*stack_a);
		else if ((*stack_a)->nb < (*stack_a)->next->nb
			&& (*stack_a)->nb > (*stack_a)->next->next->nb)
			rra(stack_a);
		else if ((*stack_a)->next->next->nb > (*stack_a)->next->nb
			&& (*stack_a)->next->next->nb < (*stack_a)->nb)
			ra(stack_a);
		else if ((*stack_a)->nb > (*stack_a)->next->nb
			&& (*stack_a)->next->nb > (*stack_a)->next->next->nb)
		{
			sa(*stack_a);
			rra(stack_a);
		}
	}
}

void	tri_4(t_list **stack_a, t_list **stack_b)
{
	if (!bonordre(*stack_a))
	{
		pb(stack_a, stack_b);
		tri_3(stack_a);
		dernier_pushback(stack_b, stack_a);
		reorder_a(stack_a);
	}
}

void	tri_moins_de_5(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		tri_2(stack_a);
	else if (size == 3)
		tri_3(stack_a);
	else if (size == 4)
		tri_4(stack_a, stack_b);
}
