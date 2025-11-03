/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:01:17 by nschilli          #+#    #+#             */
/*   Updated: 2025/10/23 12:01:17 by nschilli         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *c, size_t max)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (i >= max)
			return (max);
		i++;
	}
	return (i);
}

//size c'est taille du buffer, pas celle du string dans le buffer
//check on donne une bonne size, fait passer si size = dlen + 1
//check si y'a de la place, fait pas passer si size = dlen + 1
//size includes \0
size_t	ft_strlcat(char *dst, const char *str, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = ft_strnlen(dst, (int)size);
	i = 0;
	if (dlen < size)
	{
		while (str[i] && i < (size - dlen - 1))
		{
			dst[dlen + i] = (char)str[i];
			i++;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + ft_strlen((char *) str));
}
