/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:37:32 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/25 14:34:51 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_list	*cheapest;
	t_list	*tmp_a;
	int		nb_coups;
	int		nb_coups_cheapest;

	cheapest = stack_a;
	tmp_a = stack_a;
	nb_coups = 0;
	nb_coups_cheapest = calcul_cout_total(stack_a, stack_a, stack_b);
	while (tmp_a->next)
	{
		nb_coups = calcul_cout_total(stack_a, tmp_a, stack_b);
		if (nb_coups < nb_coups_cheapest)
		{
			cheapest = tmp_a;
			nb_coups_cheapest = nb_coups;
		}
		tmp_a = tmp_a->next;
	}
	return (cheapest);
}

void	push_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	t_list	*cheapest;
	t_list	*next_lowest;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	cheapest = find_cheapest(*stack_a, *stack_b);
	next_lowest = find_next_lowest(cheapest, *stack_b);
	if (calcul_position(*stack_a, cheapest) <= ((size_a / 2) + (size_a % 2))
		&& calcul_position(*stack_b, next_lowest) <= ((size_b / 2) + (size_b
				% 2)))
		push_rr(stack_a, stack_b, cheapest, next_lowest);
	else if (calcul_position(*stack_a, cheapest) > ((size_a / 2) + (size_a % 2))
		&& calcul_position(*stack_b, next_lowest) > ((size_b / 2) + (size_b
				% 2)))
		push_rrr(stack_a, stack_b, cheapest, next_lowest);
	else
		push_normal(stack_a, stack_b, cheapest, next_lowest);
}

void	push_normal(t_list **stack_a, t_list **stack_b, t_list *cheapest,
		t_list *next_lowest)
{
	if (calcul_position(*stack_a, cheapest) <= ((ft_lstsize(*stack_a) / 2)
			+ (ft_lstsize(*stack_a) % 2)))
	{
		while (cheapest->previous != NULL)
			ra(stack_a);
	}
	else
	{
		while (cheapest->next != NULL)
			rra(stack_a);
		rra(stack_a);
	}
	if (calcul_position(*stack_b, next_lowest) <= ((ft_lstsize(*stack_b) / 2)
			+ (ft_lstsize(*stack_b) % 2)))
	{
		while (next_lowest->previous != NULL)
			rb(stack_b);
	}
	else
	{
		while (next_lowest->next != NULL)
			rrb(stack_b);
		rrb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	push_rr(t_list **stack_a, t_list **stack_b, t_list *cheapest,
		t_list *next_lowest)
{
	while (cheapest->previous != NULL && next_lowest->previous != NULL)
		rr(stack_a, stack_b);
	while (cheapest->previous != NULL || next_lowest->previous != NULL)
	{
		if (cheapest->previous != NULL)
			ra(stack_a);
		if (next_lowest->previous != NULL)
			rb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	push_rrr(t_list **stack_a, t_list **stack_b, t_list *cheapest,
		t_list *next_lowest)
{
	while (cheapest->next != NULL && next_lowest->next != NULL)
		rrr(stack_a, stack_b);
	while (cheapest->next != NULL || next_lowest->next != NULL)
	{
		if (cheapest->next != NULL)
			rra(stack_a);
		if (next_lowest->next != NULL)
			rrb(stack_b);
	}
	rrr(stack_a, stack_b);
	pb(stack_a, stack_b);
}
