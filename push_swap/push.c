/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:38:22 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/24 13:27:38 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	if (*dest == NULL)
	{
		(*src)->next = *dest;
		*dest = *src;
		*src = tmp;
	}
	else
	{
		(*src)->next = *dest;
		(*dest)->previous = *src;
		*dest = *src;
		*src = tmp;
	}
	(*src)->previous = NULL;
}

void	dernier_pushback(t_list **stack_b, t_list **stack_a)
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
	if ((*stack_b)->next == NULL && (*stack_b)->previous == NULL)
	{
		(*stack_b)->next = *stack_a;
		(*stack_a)->previous = *stack_b;
		*stack_a = *stack_b;
		*stack_b = NULL;
	}
	ft_putstr("pa\n");
}

void	pa(t_list **pile_b, t_list **pile_a)
{
	push(pile_b, pile_a);
	ft_putstr("pa\n");
}

void	pb(t_list **pile_a, t_list **pile_b)
{
	push(pile_a, pile_b);
	ft_putstr("pb\n");
}
