/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:36:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/22 15:17:18 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	size_t		bytes_read;
	static char	*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	return (buffer);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "Wrong argument count: Must be exactly 2.\n", 41);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close (fd);
	return (0);
}
/* cc -Wall -Wextra -Werror get_next_line.c && ./a.out text1.txt */