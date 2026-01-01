/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:31:08 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 22:43:38 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	indexing(t_node **stack_a, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->is_sorted = FALSE;
	while (i < data->length)
	{
		j = 0;
		data->index = 0;
		while (j < data->length)
			if (data->buffer[i] > data->buffer[j++])
				data->index++;
		if (data->index == i)
			data->count_of_sorted_num++;
		lst_add_back(stack_a, create_node(data->buffer[i], data->index));
		i++;
	}
	if (data->count_of_sorted_num == data->length)
		data->is_sorted = TRUE;
}

void	_invoke(char **str, t_data *data)
{
	int	i;

	i = 1;
	while (str[i])
		count_and_validate(str[i++], data);
	if (data->error)
		return ;
	data->buffer = malloc(sizeof(int) * (data->length));
	i = 1;
	while (str[i])
		convert_argv_to_array(str[i++], data);
	if (!data->error)
		find_dup(data);
}

int	error(t_data *data)
{
	free(data->buffer);
	data->buffer = NULL;
	write(2, "Error\n", 6);
	return (0);
}
