/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:36:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/24 12:27:48 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	char			*line;
	size_t			i;
	size_t			j;
	
	if (BUFFER_SIZE < 1 || fd < 0 || (read(fd, buffer, BUFFER_SIZE)) < 1)
		return (NULL);
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (/*ft_strlen(line) < BUFFER_SIZE && */buffer[i] && buffer[i] != '\n')
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	if (buffer[i] == '\n')
	{
		line[j] = buffer[i];
		i++;
		return (line);
	}
	else
		return (ft_add_to_line(line, get_next_line(fd)));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*test_str;

	if (argc != 2)
	{
		write(1, "Wrong argument count: Must be exactly 2.\n", 41);
		return (1);
	}
	test_str = NULL;
	fd = open(argv[1], O_RDONLY);
	while ((test_str = get_next_line(fd)))
		printf("%s", test_str);
	free(test_str);
	close (fd);
	return (0);
}
/* cc -Wall -Wextra -Werror get_next_line.c && ./a.out text1.txt */