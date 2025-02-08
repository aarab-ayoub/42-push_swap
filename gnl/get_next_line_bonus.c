/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:01 by ayoub             #+#    #+#             */
/*   Updated: 2024/12/28 12:47:59 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (new_buffer);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_save(int fd, char *buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		b_read;

	b_read = 1;
	while (ft_strchr(buffer, '\n') == NULL && b_read)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
			break ;
		buf[b_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[10240];
	char		*tmp;

	if (fd > 10240 || fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = read_and_save(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	tmp = buffer[fd];
	line = extract_line(tmp);
	buffer[fd] = save(tmp);
	free(tmp);
	return (line);
}
