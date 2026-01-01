/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:16:30 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/30 15:19:38 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	get_min_pos(t_node *stack)
{
	int		min_rank;
	int		pos;
	int		i;

	if (!stack)
		return (-1);
	i = 0;
	pos = 0;
	min_rank = stack->rank;
	while (stack)
	{
		if (stack->rank < min_rank)
		{
			min_rank = stack->rank;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	tiny_sort(t_node **a, int length)
{
	int	first;
	int	second;
	int	third;

	if (length == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			swap(a, "sa\n", TRUE);
		return ;
	}
	first = (*a)->rank;
	second = (*a)->next->rank;
	third = (*a)->next->next->rank;
	if (first > second && first > third)
		rotate(a, "ra\n", TRUE);
	else if (second > first && second > third)
		rev_rotate(a, "rra\n", TRUE);
	if ((*a)->rank > (*a)->next->rank)
		swap(a, "sa\n", TRUE);
}

void	sort_five(t_node **a, t_node **b, int length)
{
	int	min_pos;

	while (length > 3)
	{
		min_pos = get_min_pos(*a);
		if (min_pos <= length / 2)
			while (min_pos-- > 0)
				rotate(a, "ra\n", TRUE);
		else
			while (min_pos++ < length)
				rev_rotate(a, "rra\n", TRUE);
		push(b, a, "pb\n", TRUE);
		length--;
	}
	tiny_sort(a, length);
	while (*b)
		push(a, b, "pa\n", TRUE);
}
