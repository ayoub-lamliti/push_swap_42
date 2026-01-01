/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:16:08 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 19:49:47 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate(t_node **stack, char *move_name, t_bool flag)
{
	t_node	*head;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	last = get_last_node(*stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	if (flag)
		write(1, move_name, 3);
}

void	rev_rotate(t_node **stack, char *move_name, t_bool flag)
{
	t_node	*last;
	t_node	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (flag)
		write(1, move_name, 4);
}

void	push(t_node **dest, t_node **src, char *move_name, t_bool flag)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (flag)
		write(1, move_name, 3);
}

void	swap(t_node **stack, char *move_name, t_bool flag)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (flag)
		write(1, move_name, 3);
}

void	free_stack(t_node **stack, t_data *data)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
	if (data->buffer)
	{
		free(data->buffer);
		data->buffer = NULL;
	}
}
