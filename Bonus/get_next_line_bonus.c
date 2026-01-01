/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:51:15 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 10:22:45 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	data;
	size_t			i;

	data.buf = NULL;
	while (fd >= 0 && BUFFER_SIZE > 0 && !data.is_line && !data.is_end
		&& !data.is_fail)
		read_and_do_multi_task(&data, fd);
	if (data.is_end)
	{
		if (data.len_of_buf != -1 && data.line && data.len_of_line)
		{
			i = -1;
			data.buf = ft_calloc(data.len_of_line + 1, &data);
			while (data.buf && data.len_of_line > ++i)
				data.buf[i] = data.line[i];
		}
		free(data.line);
		data.line = NULL;
	}
	data.index_new_line = 0;
	data.is_line = 0;
	return (data.buf);
}
