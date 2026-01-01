/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:12:59 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/30 14:52:09 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	get_position(t_node *stack, int rank)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

static void	phase_one(t_node **a, t_node **b, int length)
{
	int	i;
	int	range;

	if (length <= 100)
		range = 15;
	else
		range = 35;
	i = 0;
	while (*a)
	{
		if ((*a)->rank <= i)
		{
			push(b, a, "pb\n", TRUE);
			rotate(b, "rb\n", TRUE);
			i++;
		}
		else if ((*a)->rank <= i + range)
		{
			push(b, a, "pb\n", TRUE);
			i++;
		}
		else
			rotate(a, "ra\n", TRUE);
	}
}

static void	phase_two(t_node **a, t_node **b, int length)
{
	t_node	*tmp;
	int		curr_rank;
	int		pos;
	int		size_b;

	curr_rank = length - 1;
	while (*b)
	{
		size_b = 0;
		tmp = *b;
		while (tmp && ++size_b)
			tmp = tmp->next;
		pos = get_position(*b, curr_rank);
		if (pos <= size_b / 2)
			while ((*b)->rank != curr_rank)
				rotate(b, "rb\n", TRUE);
		else
			while ((*b)->rank != curr_rank)
				rev_rotate(b, "rrb\n", TRUE);
		push(a, b, "pa\n", TRUE);
		curr_rank--;
	}
}

void	butterfly_sorting(t_node **a, t_node **b, t_data *data)
{
	if (data->length <= 3)
		tiny_sort(a, data->length);
	else if (data->length <= 5)
		sort_five(a, b, data->length);
	else
	{
		phase_one(a, b, data->length);
		phase_two(a, b, data->length);
	}
}
