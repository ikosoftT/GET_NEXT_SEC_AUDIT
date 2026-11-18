/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:01 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/18 16:45:54 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	new = malloc((len + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*buffer_new_line(char *str)
{
	char	*dest;
	size_t	i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i > 0)
	{
		i--;
		dest[i] = str[i];
	}
	return (dest);
}

char	*after_new_line(char *string)
{
	char	*dest;
	char	*str;
	size_t	i;

	if (!string)
		return (NULL);
	str = string;
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	dest = NULL;
	if (*str)
		dest = malloc(ft_strlen(str) + 1);
	if (dest)
	{
		i = 0;
		while (*str)
			dest[i++] = *str++;
		dest[i] = '\0';
	}
	free(string);
	return (dest);
}
