/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:48:03 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/26 16:48:33 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **pile)
{
	t_list	*last;
	t_list	*tmp;

	if (!*pile || !(*pile)->next)
		return ;
	last = ft_lstlast(*pile);
	tmp = (*pile)->next;
	(*pile)->next = NULL;
	(*pile)->previous = last;
	last->next = *pile;
	(*pile) = tmp;
	(*pile)->previous = NULL;
}

void	ra(t_list **pile_a)
{
	rotate(pile_a);
	ft_putstr("ra\n");
}

void	rb(t_list **pile_b)
{
	rotate(pile_b);
	ft_putstr("rb\n");
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_putstr("rr\n");
}
