/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:55 by dberreby          #+#    #+#             */
/*   Updated: 2023/02/03 18:16:33 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
	struct s_list	*previous;

}					t_list;

t_list				*ft_lstnew(int nombre);
t_list				*ft_lstlast(t_list *lst);
t_list				*avant_dernier(t_list *lst);
t_list				*add_bottom(t_list **list, t_list *new);
int					ft_lstsize(t_list *lst);

t_list				*remplir_stack_a(int ac, char **av);
void				print_stack(t_list *stack);
void				print_2stack(t_list *stack_a, t_list *stack_b);

void				swap(t_list *debut);
void				push(t_list **src, t_list **dest);
void				rotate(t_list **pile);
void				reverse_rotate(t_list **pile);

int					ft_atoi(const char *nptr);
long long			ft_atoll(const char *nptr);
int					check_number(char *str);
void				ft_putstr(char *str);
int					nblen(char *str);

int					check_input(char **av);

void				sa(t_list *stack_a);
void				sb(t_list *stack_b);
void				ss(t_list *stack_a, t_list *stack_b);
void				pa(t_list **pile_b, t_list **pile_a);
void				pb(t_list **pile_a, t_list **pile_b);
void				ra(t_list **pile_a);
void				rb(t_list **pile_b);
void				rr(t_list **pile_a, t_list **pile_b);
void				rra(t_list **pile_a);
void				rrb(t_list **pile_b);
void				rrr(t_list **pile_a, t_list **pile_b);

void				algo(t_list **stack_a, t_list **stack_b);
int					bonordre(t_list *stack_a);
void				tri_3(t_list **stack_a);

t_list				*find_highest(t_list *stack);
t_list				*find_lowest(t_list *stack);
t_list				*find_next_lowest(t_list *stack_a, t_list *stack_b);
t_list				*find_next_highest(t_list *stack_a, t_list *stack_b);

int					calcul_cout_top_a(t_list *stack, t_list *element);
int					calcul_bonne_place_dans_b(t_list *element_a,
						t_list *stack_b);
int					calcul_cout_total(t_list *stack_a, t_list *element,
						t_list *stack_b);
int					calcul_position(t_list *stack, t_list *element);

int					calcul_rr(t_list *element, t_list *stack_b);
int					calcul_rrr(t_list *element, t_list *stack_b);

t_list				*find_cheapest(t_list *stack_a, t_list *stack_b);
void				push_cheapest(t_list **stack_a, t_list **stack_b);
void				push_normal(t_list **stack_a, t_list **stack_b,
						t_list *cheapest, t_list *next_lowest);
void				push_rr(t_list **stack_a, t_list **stack_b,
						t_list *cheapest, t_list *next_lowest);
void				push_rrr(t_list **stack_a, t_list **stack_b,
						t_list *cheapest, t_list *next_lowest);

void				push_back(t_list **stack_b, t_list **stack_a);
void				dernier_pushback(t_list **stack_b, t_list **stack_a);
void				reorder_a(t_list **stack_a);
void				tri_moins_de_5(t_list **stack_a, t_list **stack_b);
void				freestack(t_list **stack_a, t_list **stack_b);

char				*exec_line(char *line, t_list **stack_a, t_list **stack_b);
void				exec_line_suite(char *line, t_list **stack_a,
						t_list **stack_b);
void				ss_check(t_list *stack_a, t_list *stack_b);
void				rr_check(t_list **pile_a, t_list **pile_b);
void				rrr_check(t_list **pile_a, t_list **pile_b);
void				push_check(t_list **stack_b, t_list **stack_a);
void				ft_free(char *line, t_list **stack_a, t_list **stack_b);
void				freestack_check(t_list **stack_a, t_list **stack_b);
int					bonordre_check(t_list *stack_a);

void				freestack_a(t_list **stack_a);

#endif