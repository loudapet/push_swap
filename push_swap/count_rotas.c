/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:52:28 by plouda            #+#    #+#             */
/*   Updated: 2023/03/07 11:00:54 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Counts how many rotations are needed for the number
to reach the top of the stack a
*/
int	count_rota_a(t_clist *stack)
{
	int	i;

	i = 0;
	while (stack->start != 1)
	{
		i++;
		stack = stack->prev;
	}
	return (i);
}

/*
Counts how many reverse rotations are needed for the number
to reach the top of the stack a
*/
int	count_rev_rota_a(t_clist *stack)
{
	int	i;

	i = 0;
	while (stack->start != 1)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/*
Counts how many rotations are needed for the number
to reach the top of the stack b
*/
int	count_rota_b(t_clist *stack, int value)
{
	int	i;

	i = 0;
	if (stack->value == value && stack->start == 1)
		return (0);
	if (ft_clstsize_flag(stack) == 2)
		return (1);
	while (stack->value != value)
		stack = stack->prev;
	while (stack->start != 1)
	{
		i++;
		stack = stack->prev;
	}
	return (i);
}

/*
Counts how many reverse rotations are needed for the number
to reach the top of the stack b
*/
int	count_rev_rota_b(t_clist *stack, int value)
{
	int	i;

	i = 0;
	if (stack->value == value && stack->start == 1)
		return (0);
	while (stack->value != value)
		stack = stack->next;
	while (stack->start != 1)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
