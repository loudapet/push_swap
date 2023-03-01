/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:43:48 by plouda            #+#    #+#             */
/*   Updated: 2023/03/01 15:57:27 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*create_stack_a(int argc, const char **argv)
{
	t_clist	*stack_a;
	int	value;
	int	i;

	i = 1;
	value = ft_atoi(argv[i++]);
	stack_a = ft_clstnew(value);
	stack_a->start = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		ft_clstadd_back(&stack_a, ft_clstnew(value));
		i++;
	}
	ft_clstlast(stack_a)->next = stack_a;
	while (stack_a->next->prev == NULL)
	{
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
	}
	return (stack_a);
}

t_clist	*create_stack_b(void)
{
	t_clist	*stack_b;

	stack_b = ft_clstnew(0);
	stack_b->start = 0;
	return (stack_b);
}

void	free_stack(t_clist **stack)
{
	t_clist	*next;
	t_clist	*tmp;

	if (stack && *stack)
	{
		next = (*stack)->next;
		while (next && (next != *stack))
		{
			tmp = next;
			next = next->next;
			free(tmp);
		}
		free(*stack);
		*stack = NULL;
	}
}

int	main(int argc, const char **argv)
{
	t_clist		*stack_a;
	t_clist		*stack_b;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	ft_printf("%s", "\n_________TESTING-PROGRAM_________\n");
	stack_a = create_stack_a(argc, argv);
	stack_b = create_stack_b();
	ft_printf("Initial size of A: %d\n\n", ft_clstsize_flag(stack_a));
	print_clist_a(stack_a);
	print_clist_b(stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	print_clist_a(stack_a);
	print_clist_b(stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	print_clist_a(stack_a);
	print_clist_b(stack_b);
	ft_printf("%d\n", max_value(stack_a));
	ft_printf("%d\n", min_value(stack_a));
	/*
	ft_printf("%d\n", count_rota(stack_a, 5));
	ft_printf("%d\n", count_rev_rota(stack_a, 5));
	swap(stack_a);
	print_clist_swap(stack_a);
	swap(stack_a);
	print_clist_rev(stack_a);
	swap(stack_a);
	print_clist_rev_swap(stack_a);
	swap(stack_a);
	rotate(stack_a);
	print_clist_rotated(stack_a);
	reverse_rotate(stack_a);
	reverse_rotate(stack_a);
	print_clist_rev_rotated(stack_a);
	*/
	free_stack(&stack_a);
	free_stack(&stack_b);

	return (0);
}
