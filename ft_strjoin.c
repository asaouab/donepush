/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:21:51 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/12 01:30:02 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_help(char **strs, char *s, char *sep, int size)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			s[c++] = sep[j++];
		i++;
	}
	s[c] = '\0';
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	c = strlen(sep);
	j = 0;
	while (strs[j])
	{
		i = i + strlen(strs[j]);
		j++;
	}
	i += (c * (j - 1));
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s = join_help(strs, s, sep, size);
	return (s);
}
