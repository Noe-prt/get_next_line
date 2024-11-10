/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:36:31 by nopareti           #+#    #+#            */
/*   Updated: 2024/11/10 18:41:41 by npareti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "Libft/libft.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	size_t		bytes_read;
	char		*stash;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	stash = NULL;
	bytes_read = 0;
	while (!contain_line(stash))
	{
		bytes_read = read(fd, buffer, 5);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		char *temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		if (!stash)
			break;
	}
	free(buffer);
	return (stash - contain_line(stash));
}

int	main(void)
{
	int	fd = open("readme.txt", O_RDONLY);
	char *gnl = get_next_line(fd);
	ft_putstr(gnl);
	free(gnl);
	return (0);
}
