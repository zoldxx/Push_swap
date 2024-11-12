/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:49:34 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/03 17:51:27 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_zero(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	is_dif(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (s1[i] == '-' && s2[k] == '-')
	{
		i++;
		k++;
	}
	while (s1[i] == '+' || s1[i] == '0')
		i++;
	while (s2[k] == '+' || s2[k] == '0')
		k++;
	while (s1[i] != '\0' && s2[k] != '\0')
	{
		if (s1[i] != s2[k])
			return (1);
		i++;
		k++;
	}
	if (s1[i] == '\0' && s2[k] == '\0')
		return (0);
	return (1);
}

int	check_doublon(char **av)
{
	int	i;
	int	n;
	int	r;

	i = 1;
	n = 2;
	r = 1;
	while (av[i])
	{
		while (av[n])
		{
			r = is_dif(av[i], av[n]);
			if (!r)
				return (0);
			n++;
		}
		i++;
		n = i + 1;
	}
	return (1);
}

int	check_int(char **av)
{
	long long	nb;
	int			i;

	nb = 0;
	i = 1;
	while (av[i])
	{
		if (nblen(av[i]) > 11)
			return (0);
		nb = ft_atoll(av[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **av)
{
	int	i;
	int	nbzero;

	i = 1;
	nbzero = 0;
	while (av[i])
	{
		if (!check_number(av[i]))
			return (0);
		if (is_zero(av[i]))
			nbzero++;
		i++;
	}
	if (nbzero > 1)
		return (0);
	if (!check_int(av))
		return (0);
	if (!check_doublon(av))
		return (0);
	return (1);
}
