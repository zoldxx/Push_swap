/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:31:01 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/03 17:59:50 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (r * s);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	nblen(char *str)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[1] == '0')
		{
			z = 1;
			while (str[z] == '0')
				z++;
			z--;
		}
	}
	else
	{
		while (str[z] == '0')
			z++;
	}
	while (str[i + z])
		i++;
	return (i);
}

int	calcul_position(t_list *stack, t_list *element)
{
	int	i;

	i = 1;
	while (stack != element)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
