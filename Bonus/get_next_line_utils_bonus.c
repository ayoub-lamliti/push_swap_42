/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamliti <alamliti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:51:47 by alamliti          #+#    #+#             */
/*   Updated: 2025/12/31 10:22:33 by alamliti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

void	*ft_calloc(size_t size, t_list *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		data->is_fail = 1;
		if (data->buf)
			free(data->buf);
		if (data->line)
			free(data->line);
		data->buf = NULL;
		data->line = NULL;
		return (NULL);
	}
	while (size-- > 0)
		((char *)ptr)[size] = 0;
	return (ptr);
}

void	find_new_line(t_list *data)
{
	size_t	i;

	i = 0;
	while (data->line && data->len_of_line > i)
	{
		if (data->line[i] == '\n')
		{
			data->index_new_line = i + 1;
			data->is_line = 1;
			return ;
		}
		i++;
	}
}

void	buf_and_remainder(t_list *data)
{
	size_t	j;
	size_t	i;
	char	*temp_line;

	i = -1;
	j = -1;
	if (data->is_line)
	{
		data->buf = ft_calloc(data->index_new_line + 1, data);
		if (!data->buf)
			return ;
		while (++i < data->index_new_line)
			data->buf[i] = data->line[i];
		data->len_of_line = data->len_of_line - data->index_new_line;
		i = data->index_new_line;
		temp_line = ft_calloc(data->len_of_line + 1, data);
		if (!temp_line)
			return ;
		while (++j <= data->len_of_line)
			temp_line[j] = data->line[i++];
		free(data->line);
		data->line = temp_line;
	}
}

void	ft_strjoin(t_list *data)
{
	size_t	i;
	char	*temp_line;

	i = -1;
	if (!data->buf)
		return ;
	temp_line = ft_calloc(data->len_of_line + data->len_of_buf + 1, data);
	if (!temp_line)
		return ;
	while (data->len_of_line && data->len_of_line > ++i)
		temp_line[i] = data->line[i];
	i = -1;
	while (data->len_of_buf && (size_t)data->len_of_buf > ++i)
		temp_line[data->len_of_line + i] = data->buf[i];
	free(data->line);
	free(data->buf);
	data->line = NULL;
	data->line = temp_line;
	data->len_of_line = data->len_of_line + data->len_of_buf;
	find_new_line(data);
	if (data->is_line)
		buf_and_remainder(data);
}

void	read_and_do_multi_task(t_list *data, int fd)
{
	find_new_line(data);
	if (!data->is_line)
	{
		data->buf = ft_calloc(BUFFER_SIZE + 1, data);
		if (!data->buf)
			return ;
		data->len_of_buf = read(fd, data->buf, BUFFER_SIZE);
		if (data->len_of_buf <= 0)
		{
			data->is_end = 1;
			free(data->buf);
			data->buf = NULL;
			return ;
		}
		else
			ft_strjoin(data);
	}
	else
		buf_and_remainder(data);
	if (data->line && !*(data->line) && !data->len_of_line)
	{
		free(data->line);
		data->line = NULL;
	}
}
