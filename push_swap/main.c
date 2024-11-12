/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:08:57 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/03 14:35:38 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bonordre(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 5)
		tri_moins_de_5(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		while (ft_lstsize(*stack_a) > 3 && !bonordre(*stack_a))
		{
			push_cheapest(stack_a, stack_b);
		}
		if (ft_lstsize(*stack_a) == 3)
			tri_3(stack_a);
		while (ft_lstsize(*stack_b) > 1)
			push_back(stack_b, stack_a);
		dernier_pushback(stack_b, stack_a);
		reorder_a(stack_a);
	}
}

void	freestack(t_list **stack_a, t_list **stack_b)
{
	t_list	*rpz;
	t_list	*tmp;

	rpz = *stack_a;
	if (!stack_a && !stack_b)
		return ;
	while (rpz)
	{
		tmp = rpz->next;
		free(rpz);
		rpz = tmp;
	}
	free(*stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!check_input(av))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	if (ac > 2)
	{
		stack_a = remplir_stack_a(ac, av);
		if (stack_a == NULL)
			exit(0);
		stack_b = NULL;
		if (!bonordre(stack_a))
			push_swap(&stack_a, &stack_b);
		freestack(&stack_a, &stack_b);
	}
	return (0);
}
