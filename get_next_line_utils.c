/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:37:10 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/23 15:07:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;
    size_t  i;

	s = count * size;
	dst = malloc(s);
	if (dst == NULL)
		return (NULL);
    i = 0;
	while (i < s)
    {
        *(unsigned char *)(dst + i) = (unsigned char)0;
        i++;
    }
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_add_to_line(char *line, char *to_add)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!to_add)
		return (line);
	s = ft_calloc((ft_strlen(line) + ft_strlen(to_add) + 1), sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (line[i])
	{
		s[i] = line[i];
		i++;
	}
	j = 0;
	while (to_add[j])
	{
		s[i + j] = to_add[j];
		j++;
	}
	free(line);
	free(to_add);
	return (s);
}
