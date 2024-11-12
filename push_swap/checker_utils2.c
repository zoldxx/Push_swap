/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:58:43 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/01 13:34:17 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*rpz;
	t_list	*tmp;
	t_list	*rpzb;
	t_list	*tmpb;

	rpz = *stack_a;
	rpzb = *stack_b;
	if (!stack_a && !stack_b)
		return ;
	while (rpz)
	{
		tmp = rpz->next;
		free(rpz);
		rpz = tmp;
	}
	while (rpzb)
	{
		tmpb = rpzb->next;
		free(rpzb);
		rpzb = tmpb;
	}
}

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
