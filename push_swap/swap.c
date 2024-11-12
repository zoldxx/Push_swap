/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:51 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/25 18:35:24 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *debut)
{
	int	tmp;

	if (!debut || !debut->next)
		return ;
	tmp = debut->nb;
	debut->nb = debut->next->nb;
	debut->next->nb = tmp;
}

void	sa(t_list *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
