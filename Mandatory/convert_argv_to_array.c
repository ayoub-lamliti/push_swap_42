/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argv_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-lec <ayoub-lec@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:15:32 by alamliti          #+#    #+#             */
/*   Updated: 2026/01/01 00:53:33 by ayoub-lec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	skip_and_sign(char **str, int *sign)
{
	*sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

void	convert_argv_to_array(char *str, t_data *data)
{
	long	num;
	int		sign;

	while (*str)
	{
		skip_and_sign(&str, &sign);
		if (!*str)
			break ;
		num = 0;
		while (*str >= '0' && *str <= '9')
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
		data->buffer[data->index++] = (int)(num * sign);
	}
}
