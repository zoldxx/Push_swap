/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:44:29 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/25 14:37:06 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_cout_top_a(t_list *stack, t_list *element)
{
	int	nb_coups;
	int	size;

	nb_coups = 0;
	size = ft_lstsize(stack);
	if (calcul_position(stack, element) > ((size / 2) + (size % 2)))
	{
		while (element->next)
		{
			element = element->next;
			nb_coups++;
		}
		return (nb_coups + 1);
	}
	else
	{
		while (element->previous)
		{
			element = element->previous;
			nb_coups++;
		}
		return (nb_coups);
	}
}

int	calcul_bonne_place_dans_b(t_list *element_a, t_list *stack_b)
{
	int		nb_coups;
	int		size;
	t_list	*next_lowest;

	nb_coups = 0;
	size = ft_lstsize(stack_b);
	next_lowest = find_next_lowest(element_a, stack_b);
	if (calcul_position(stack_b, next_lowest) > ((size / 2) + (size % 2)))
	{
		while (next_lowest->next)
		{
			next_lowest = next_lowest->next;
			nb_coups++;
		}
		return (nb_coups + 1);
	}
	else
	{
		while (next_lowest->previous)
		{
			next_lowest = next_lowest->previous;
			nb_coups++;
		}
		return (nb_coups);
	}
}

int	calcul_cout_total(t_list *stack_a, t_list *element, t_list *stack_b)
{
	int		i;
	int		size_a;
	int		size_b;
	t_list	*next_lowest;

	i = 0;
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	next_lowest = find_next_lowest(element, stack_b);
	if (calcul_position(stack_a, element) <= ((size_a / 2) + (size_a % 2))
		&& calcul_position(stack_b, next_lowest) <= ((size_b / 2) + (size_b
				% 2)))
		i = calcul_rr(element, stack_b);
	else if (calcul_position(stack_a, element) > ((size_a / 2) + (size_a % 2))
		&& calcul_position(stack_b, next_lowest) > ((size_b / 2) + (size_b
				% 2)))
		i = calcul_rrr(element, stack_b);
	else
		i = calcul_cout_top_a(stack_a, element)
			+ calcul_bonne_place_dans_b(element, stack_b);
	return (i + 1);
}

int	calcul_rr(t_list *element, t_list *stack_b)
{
	int		nb_coups;
	t_list	*next_lowest;

	nb_coups = 0;
	next_lowest = find_next_lowest(element, stack_b);
	while (element->previous != NULL && next_lowest->previous != NULL)
	{
		element = element->previous;
		next_lowest = next_lowest->previous;
		nb_coups++;
	}
	while (element->previous != NULL || next_lowest->previous != NULL)
	{
		if (element->previous != NULL)
			element = element->previous;
		else if (next_lowest->previous != NULL)
			next_lowest = next_lowest->previous;
		nb_coups++;
	}
	return (nb_coups);
}

int	calcul_rrr(t_list *element, t_list *stack_b)
{
	int		nb_coups;
	t_list	*next_lowest;

	nb_coups = 0;
	next_lowest = find_next_lowest(element, stack_b);
	while (element->next != NULL && next_lowest->next != NULL)
	{
		element = element->next;
		next_lowest = next_lowest->next;
		nb_coups++;
	}
	while (element->next != NULL || next_lowest->next != NULL)
	{
		if (element->next != NULL)
			element = element->next;
		else if (next_lowest->next != NULL)
			next_lowest = next_lowest->next;
		nb_coups++;
	}
	return (nb_coups + 1);
}
