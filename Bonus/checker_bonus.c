/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:50:09 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 21:18:07 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

int	main(int n, char **c)
{
	static t_node	*a;
	static t_node	*b;
	static t_data	data;

	if (n > 1)
	{
		_invoke(c, &data);
		if (data.error)
			return (error(&data));
		indexing(&a, &data);
		while (!data.flag)
		{
			instructions(&a, &b, get_next_line(0), &data);
			if (data.error)
				break ;
		}
		check_if_sorted(a, b, &data);
	}
	free_stack(&a, &data);
	free_stack(&b, &data);
	return (0);
}
