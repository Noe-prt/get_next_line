/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:36:31 by nopareti           #+#    #+#            */
/*   Updated: 2024/11/11 21:46:56 by npareti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contain_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	return (i);
}

char	*fill_stash(char *buff)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	length = ft_strlen(buff) - get_line_length(buff);
	char	*stash = malloc(sizeof(char) * length);
	if (!stash)
		return (NULL);
	while (buff[i] != '\n')
		i++;
	i++;
	while (buff[i])
		stash[j++] = buff[i++];
	stash[j] = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int	bytes_read;
	char	*line;
	static char	*stash;
	size_t	i;
		
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	line = ft_strdup("");
	if (stash == NULL)
		stash = ft_strdup("");
	while (stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	stash = NULL;
	i = 0;
	while (!contain_line(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	stash = fill_stash(buffer);
	if (!stash)
		return (NULL);
	free(buffer);
	line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(stash) - 1);
	return (line);
}

int	main(void)
{
	int	fd = open("readme.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		ft_putnbr_fd(i + 1, 1);
		ft_putstr_fd(".", 1);
		ft_putstr_fd(get_next_line(fd), 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
