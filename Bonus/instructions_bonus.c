/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-lec <ayoub-lec@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:20:56 by alamliti          #+#    #+#             */
/*   Updated: 2026/01/01 00:51:37 by ayoub-lec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

static void	rr(t_node **a, t_node **b, char *instruct)
{
	rotate(a, instruct, FALSE);
	rotate(b, instruct, FALSE);
}

static void	rrr(t_node **a, t_node **b, char *instruct)
{
	rev_rotate(a, instruct, FALSE);
	rev_rotate(b, instruct, FALSE);
}

static void	_switch(t_node **a, t_node **b, char *instruct, t_data *data)
{
	if (stringcmp(instruct, "ra\n"))
		rotate(a, instruct, FALSE);
	else if (stringcmp(instruct, "rb\n"))
		rotate(b, instruct, FALSE);
	else if (stringcmp(instruct, "pa\n"))
		push(a, b, instruct, FALSE);
	else if (stringcmp(instruct, "pb\n"))
		push(b, a, instruct, FALSE);
	else if (stringcmp(instruct, "rra\n"))
		rev_rotate(a, instruct, FALSE);
	else if (stringcmp(instruct, "rrb\n"))
		rev_rotate(b, instruct, FALSE);
	else if (stringcmp(instruct, "sa\n"))
		swap(a, instruct, FALSE);
	else if (stringcmp(instruct, "rr\n"))
		rr(a, b, instruct);
	else if (stringcmp(instruct, "rrr\n"))
		rrr(a, b, instruct);
	else
		data->error++;
}

void	instructions(t_node **a, t_node **b, char *instruct, t_data *data)
{
	if (instruct)
		_switch(a, b, instruct, data);
	else
		data->flag = TRUE;
	free(instruct);
}
