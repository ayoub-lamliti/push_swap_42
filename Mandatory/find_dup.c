/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:15:54 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/30 14:43:34 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	find_dup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->length)
	{
		j = i;
		while ((j + 1) < data->length)
		{
			if (data->buffer[i] == data->buffer[j + 1])
				data->error++;
			j++;
		}
		i++;
	}
}
