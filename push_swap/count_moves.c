/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:13:22 by plouda            #+#    #+#             */
/*   Updated: 2023/03/02 12:14:17 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	init_count(int rota_a, int rota_b, int rev_rota_a, int rev_rota_b)
{
	t_count	count;

	count.rota_a = rota_a;
	count.rota_b = rota_b;
	count.rev_rota_a = rev_rota_a;
	count.rev_rota_b = rev_rota_b;
	count.rot = 0;
	count.rev_rot = 0;
	count.diff_a_b = 0;
	count.diff_b_a = 0;
	count.fin_rot = 0;
	count.fin_diff = 0;
	count.flag_rot_diff = 'x';
	count.flag_rev_rot_a_b = 'x';
	return (count);
}

/*
flag_rot_diff: decides if the preference is to rotate both stacks at once,
				or if it is cheaper to rotate them separately
options:	's': rotate stacks separately
			't': rotate stacks together
*/
t_count	resolve_rot_diff(t_count count)
{
	if (count.rot > count.rev_rot)
		count.fin_rot = count.rev_rot;
	else
		count.fin_rot = count.rot;
	if (count.diff_a_b > count.diff_b_a)
		count.fin_diff = count.diff_b_a;
	else
		count.fin_diff = count.diff_a_b;
	if (count.fin_rot > count.fin_diff)
		count.flag_rot_diff = 's';
	else
		count.flag_rot_diff = 't';
	return (count);
}

/*
flag_a_b: decides whether to rotate stack a and rev_rotate stack b or vice versa
options:	'b': rotate stack b, reverse rotate stack a
			'a': rotate stack a, reverse rotate stack b
*/
t_count	resolve_rev_rot(t_count count)
{
	if (count.diff_a_b > count.diff_b_a)
		count.flag_rev_rot_a_b = 'b';
	else
		count.flag_rev_rot_a_b = 'a';
	return (count);
}

/*
flag_a_b: decides if the preference is to rotate or rev_rotate both stacks
options:	'd': reverse rotate both stacks
			'c': rotate both stacks
*/
t_count	resolve_a_b(t_count count)
{
	if (count.rot > count.rev_rot)
		count.flag_rev_rot_a_b = 'd';
	else
		count.flag_rev_rot_a_b = 'c';
	return (count);
}

t_count	count_diff(int rota_a, int rota_b, int rev_rota_a, int rev_rota_b)
{
	t_count	count;

	count = init_count(rota_a, rota_b, rev_rota_a, rev_rota_b);
	if (count.rota_a > count.rota_b)
		count.rot = count.rota_a;
	else
		count.rot = rota_b;
	if (count.rev_rota_a > count.rev_rota_b)
		count.rev_rot = count.rev_rota_a;
	else
		count.rev_rot = count.rev_rota_b;
	count.diff_a_b = count.rota_a + count.rev_rota_b;
	count.diff_b_a = count.rota_b + count.rev_rota_a;
	count = resolve_rot_diff(count);
	if (count.flag_rot_diff == 's')
		count = resolve_rev_rot(count);
	else if (count.flag_rot_diff == 't')
		count = resolve_a_b(count);
	return (count);
}

int	count_rota(t_clist *stack, int value)
{
	int	i;

	i = 1;
	if (stack->value == value)
		return (0);
	stack = stack->next;
	while (stack->value != value && stack->start != 1)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_rev_rota(t_clist *stack, int value)
{
	int	i;

	i = 1;
	if (stack->value == value)
		return (0);
	stack = stack->prev;
	while (stack->value != value && stack->start != 1)
	{
		i++;
		stack = stack->prev;
	}
	return (i);
}
