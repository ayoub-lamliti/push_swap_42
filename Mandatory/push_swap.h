/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-lec <ayoub-lec@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:16:20 by alamliti          #+#    #+#             */
/*   Updated: 2026/01/01 00:50:08 by ayoub-lec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_bool;

typedef struct node
{
	int			value;
	int			rank;
	struct node	*next;
}	t_node;

typedef struct data
{
	int		length;
	int		index;
	int		count_of_sorted_num;
	int		error;
	int		*buffer;
	char	*str;
	t_bool	is_sorted;
	t_bool	is_number;
	t_bool	flag;
}	t_data;

t_node	*create_node(long value, int rank);
t_node	*get_last_node(t_node *lst);
void	lst_add_back(t_node **lst, t_node *new);
void	convert_argv_to_array(char *str, t_data *data);
void	count_and_validate(char *str, t_data *data);
void	push(t_node **dest, t_node **src, char *move_name, t_bool flag);
void	rev_rotate(t_node **stack, char *move_name, t_bool flag);
void	rotate(t_node **stack, char *move_name, t_bool flag);
void	swap(t_node **stack, char *move_name, t_bool flag);
void	free_stack(t_node **stack, t_data *data);
void	find_dup(t_data *data);
void	butterfly_sorting(t_node **a, t_node **b, t_data *data);
void	sort_five(t_node **a, t_node **b, int length);
void	tiny_sort(t_node **a, int length);
void	find_dup(t_data *data);
void	indexing(t_node **stack_a, t_data *data);
void	_invoke(char **str, t_data *data);
int		error(t_data *data);

#endif