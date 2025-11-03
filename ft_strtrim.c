/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:02:23 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 02:03:04 by nschilli         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

// true/false
static int	validchar(char c, char *tormv)
{
	size_t	i;

	i = 0;
	while (tormv[i])
	{
		if (tormv[i] == c)
			return (0);
		i++;
	}
	return (1);
}

// xxsalutxx\0
// 012345678.9
// sluttion 8
// si str == set ?
static size_t	mallength(char *str, char *set, size_t *start, size_t *end)
{
	while (!validchar(str[*start], set) && str[(*start)])
		(*start)++;
	while (!validchar(str[*end - 1], set) && *end > *start)
		(*end)--;
	return (*end - *start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	len = mallength((char *)s1, (char *)set, &start, &end);
	if (len <= 0)
		return (ft_strdup(""));
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	while (start < end)
		out[i++] = (char) s1[start++];
	out[i] = '\0';
	return (out);
}
