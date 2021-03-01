/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:58:35 by khee-seo          #+#    #+#             */
/*   Updated: 2021/01/22 01:52:35 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_split(char **backup, char *line, int cut_index)
{
	char	*temp;
	int		i;

	if (!(line = (char *)malloc(sizeof(char) * (cut_index + 1))))
		return (0);
	i = 0;
	while (i < cut_index)
	{
		line[i] = (*backup)[i];
		i++;
	}
	line[i] = '\0';
	temp = ft_strdup(*backup + cut_index + 1);
	free(*backup);
	*backup = temp;
	return (line);
}

char	*line_cpy(char *backup, char *line)
{
	if (backup == 0)
	{
		if (!(line = (char *)malloc(sizeof(char))))
			return (0);
		*line = '\0';
		free(backup);
		return (line);
	}
	line = ft_strdup(backup);
	free(backup);
	return (line);
}

char	*save(char *backup, char *buf)
{
	char	*temp;

	if (backup == NULL)
	{
		backup = ft_strdup(buf);
	}
	else
	{
		temp = ft_strjoin(backup, buf);
		free(backup);
		backup = temp;
	}
	return (backup);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				cut_index;
	int				rd;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (1)
	{
		if (0 <= (cut_index = ft_strchr(backup[fd], '\n')))
		{
			*line = line_split(&backup[fd], *line, cut_index);
			return (1);
		}
		if (0 == (rd = read(fd, buf, BUFFER_SIZE)))
			break ;
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		backup[fd] = save(backup[fd], buf);
	}
	*line = line_cpy(backup[fd], *line);
	backup[fd] = 0;
	return (0);
}
