/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:10:04 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/29 14:18:02 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_trim_storage(char *storage)
{
	char	*new_storage;
	size_t	i;
	size_t	j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		return (NULL);
	}
	new_storage = ft_calloc((ft_strlen(storage) - i + 1), sizeof(char));
	if (!new_storage)
		return (NULL);
	i = i + 1;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free (storage);
	return (new_storage);
}

char	*ft_send_to_print(char *storage)
{
	char	*to_print;
	size_t	i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	to_print = ft_calloc((i + 2), sizeof(char));
	if (!to_print)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		to_print[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		to_print[i] = storage[i];
		i++;
	}
	to_print[i] = '\0';
	return (to_print);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*to_print;
	int			bytes_read;
	static char	*storage[1024];

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	bytes_read = 1;
	while (0 < bytes_read && !ft_strchr(storage[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buffer);
	}
	if (bytes_read == -1)
		free(storage[fd]);
	if (!storage[fd])
		return (NULL);
	to_print = ft_send_to_print(storage[fd]);
	storage[fd] = ft_trim_storage(storage[fd]);
	return (to_print);
}

/* int	main(int argc, char **argv)
{
	int		fd[1024];
	int		i;
	char	*test_str;

	if (argc < 3)
	{
		write(1, "Wrong argument count: Must be al least 3.\n", 41);
		return (1);
	}
	test_str = NULL;
	i = 1;
	while (i < argc)
	{
		fd[i] = open(argv[i], O_RDONLY);
		if (fd[i] == -1)
		{
			write (1, "Error: Could not open file\n", 27);
			return (1);
		}
		i++;
	}
	i = 1;
	while ((test_str = get_next_line(fd[i])))
	{
		printf("%i -> %s", i, test_str);
		free(test_str);
		i++;
		if (i == argc)
			i = 1;
	}
	while (1 < argc)
	{
		close(fd[argc - 1]);
		argc--;
	}
	return (0);
} */
/* cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils.c */