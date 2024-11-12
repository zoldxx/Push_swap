/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:57 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/15 15:17:53 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*remplir_stack_a(int ac, char **av)
{
	int		i;
	t_list	*stack_a;
	t_list	*tmp;

	stack_a = ft_lstnew(ft_atoi(av[1]));
	if (stack_a == NULL)
		return (NULL);
	tmp = stack_a;
	i = 2;
	while (i < ac)
	{
		tmp = add_bottom(&tmp, ft_lstnew(ft_atoi(av[i])));
		if (tmp == NULL)
			freestack_a(&stack_a);
		i++;
	}
	stack_a = tmp;
	return (stack_a);
}

void	freestack_a(t_list **stack_a)
{
	t_list	*rpz;
	t_list	*tmp;

	rpz = *stack_a;
	if (!stack_a)
		return ;
	while (rpz)
	{
		tmp = rpz->next;
		free(rpz);
		rpz = tmp;
	}
	exit(0);
}
