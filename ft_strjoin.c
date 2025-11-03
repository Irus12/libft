/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 03:09:17 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 03:13:20 by nschilli         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//+1 au malloc pour le \0

static void building(char *out, char const *s1, char const *s2 )
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		out[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		out[i] = s2[j];
		j++;
		i++;
	}
	out[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	out = malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	building(out, s1, s2);
	return (out);
}
