/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:37:34 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:51 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static char	*ft_free1(char *arr)
{
	free(arr);
	return (NULL);
}

static char	*read_line(int fd, char *buf, char *back_up)
{
	int		read_byte;
	char	*tmp_point;

	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (ft_free1(back_up));
		if (read_byte == 0)
			break ;
		buf[read_byte] = '\0';
		tmp_point = back_up;
		back_up = ft_strjoin(back_up, buf);
		free(tmp_point);
		if (!back_up)
			return (NULL);
		if (ft_strchr(back_up, '\n'))
			break ;
	}
	return (back_up);
}

static char	*substring_line(char *tmp)
{
	int		i;
	char	*line;

	if (tmp == 0 || tmp[0] == '\0')
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = ft_substr(tmp, 0, i + 1);
	return (line);
}

static char	*substring_back_up(char *tmp, char **line)
{
	char	*back_up;
	int		i;

	i = 0;
	if (tmp == 0)
		return (NULL);
	if (tmp[0] == '\0')
		return (ft_free1(tmp));
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (tmp[i] == '\0')
		return (ft_free1(tmp));
	back_up = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	if (!back_up)
	{
		free(*line);
		*line = NULL;
		return (ft_free1(tmp));
	}
	free(tmp);
	return (back_up);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	char		*tmp;
	static char	*back_up;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!back_up)
	{
		back_up = ft_strdup("");
		if (!back_up)
			return (ft_free1(buf));
	}
	tmp = read_line(fd, buf, back_up);
	free(buf);
	line = substring_line(tmp);
	back_up = substring_back_up(tmp, &line);
	return (line);
}
