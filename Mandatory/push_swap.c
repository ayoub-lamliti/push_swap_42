/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:31:08 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 20:50:55 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int n, char **c)
{
	static t_node	*stack_a;
	static t_node	*stack_b;
	static t_data	data;

	stack_a = NULL;
	stack_b = NULL;
	if (n > 1)
	{
		_invoke(c, &data);
		if (data.error)
		{
			error(&data);
			return (0);
		}
		indexing(&stack_a, &data);
		if (!data.is_sorted)
			butterfly_sorting(&stack_a, &stack_b, &data);
	}
	free_stack(&stack_a, &data);
	free_stack(&stack_b, &data);
	return (0);
}
