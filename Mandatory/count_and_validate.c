/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-lec <ayoub-lec@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:15:41 by alamliti          #+#    #+#             */
/*   Updated: 2026/01/01 00:53:12 by ayoub-lec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	skip_spaces_and_sign(char **str, int *sign, t_data *data)
{
	*sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
		if (!**str || !(**str >= '0' && **str <= '9'))
			data->error++;
	}
}

static void	check_and_count(char **str, int sign, t_data *data)
{
	long	num;

	num = 0;
	if (!**str || !(**str >= '0' && **str <= '9'))
	{
		data->error++;
		return ;
	}
	while (**str >= '0' && **str <= '9')
	{
		num = (num * 10) + (**str - '0');
		(*str)++;
	}
	if ((**str && **str != ' ' && !(**str >= '\t' && **str <= '\r'))
		|| (num * sign) > INT_MAX || (num * sign) < INT_MIN)
		data->error++;
	else
		data->length++;
}

void	count_and_validate(char *str, t_data *data)
{
	int		sign;
	char	*tmp;

	tmp = str;
	while (*tmp == ' ' || (*tmp >= '\t' && *tmp <= '\r'))
		tmp++;
	if (!*tmp)
	{
		data->error++;
		return ;
	}
	while (*str)
	{
		skip_spaces_and_sign(&str, &sign, data);
		if (data->error)
			return ;
		if (!*str)
			break ;
		check_and_count(&str, sign, data);
		if (data->error)
			return ;
	}
}
