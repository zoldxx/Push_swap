/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:48 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/01 15:20:03 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	ft_free(char *line, t_list **stack_a, t_list **stack_b)
{
	ft_putstr("Error\n");
	freestack_check(stack_a, stack_b);
	free(line);
}

char	*exec_line(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap(*stack_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap(*stack_b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss_check(*stack_a, *stack_b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_check(stack_b, stack_a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_check(stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate(stack_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr_check(stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		exec_line_suite(line, stack_a, stack_b);
	else
	{
		ft_free(line, stack_a, stack_b);
		get_next_line(0, 1);
		exit(0);
	}
	return (get_next_line(0, 0));
}

void	exec_line_suite(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[2] == 'a')
		reverse_rotate(stack_a);
	else if (line[2] == 'b')
		reverse_rotate(stack_b);
	else if (line[2] == 'r')
		rrr_check(stack_a, stack_b);
	else
	{
		ft_putstr("Error\n");
		freestack_check(stack_a, stack_b);
		free(line);
		get_next_line(0, 1);
		exit(0);
	}
}

void	boucle(char *line, t_list **stack_a, t_list **stack_b)
{
	char	*tmp;

	while (line != NULL)
	{
		tmp = line;
		line = exec_line(line, stack_a, stack_b);
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	if (!check_input(av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ac > 2)
	{
		stack_a = remplir_stack_a(ac, av);
		stack_b = NULL;
		line = get_next_line(0, 0);
		boucle(line, &stack_a, &stack_b);
		if (bonordre_check(stack_a) && stack_b == NULL)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		freestack_check(&stack_a, &stack_b);
	}
	return (0);
}
