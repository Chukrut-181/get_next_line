/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:37:10 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/21 15:08:37 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;
	size_t	i;

	s = count * size;
	dst = malloc(s);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*((unsigned char *)(dst + i)) = (unsigned char)0;
		i++;
	}
	return (dst);
}
