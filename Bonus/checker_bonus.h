/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:16:20 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 20:04:28 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include "../Mandatory/push_swap.h"

typedef struct list
{
	int		is_fail;
	int		is_end;
	int		is_line;
	size_t	index_new_line;
	size_t	len_of_line;
	ssize_t	len_of_buf;
	char	*line;
	char	*buf;
}	t_list;

char	*get_next_line(int fd);
void	read_and_do_multi_task(t_list *data, int fd);
void	ft_strjoin(t_list *data);
void	buf_and_remainder(t_list *data);
void	find_new_line(t_list *data);
void	*ft_calloc(size_t size, t_list *data);
void	instructions(t_node **a, t_node **b, char *instruct, t_data *data);
void	check_if_sorted(t_node *stack_a, t_node *stack_b, t_data *data);
int		stringcmp(const char *s1, const char *s2);

#endif