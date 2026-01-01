/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:04:49 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 21:17:48 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

void	check_if_sorted(t_node *stack_a, t_node *stack_b, t_data *data)
{
	if (stack_b || data->error)
	{
		if (data->error)
			write(2, "Error\n", 6);
		else
			write(1, "KO\n", 3);
		return ;
	}
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
}
