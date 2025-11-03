/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:50:04 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 02:50:04 by nschilli         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//si un param est null segfault, si les deux return null
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (!cdest && !csrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
