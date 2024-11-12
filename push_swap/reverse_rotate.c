/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:51:09 by dberreby          #+#    #+#             */
/*   Updated: 2023/01/26 16:53:48 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **pile)
{
	t_list	*ad;
	t_list	*last;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	ad = avant_dernier(*pile);
	last = ft_lstlast(*pile);
	last->next = *pile;
	(*pile)->previous = last;
	last->previous = NULL;
	*pile = last;
	ad->next = NULL;
	ad->previous = avant_dernier(*pile);
}

void	rra(t_list **pile_a)
{
	reverse_rotate(pile_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **pile_b)
{
	reverse_rotate(pile_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **pile_a, t_list **pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	ft_putstr("rrr\n");
}
