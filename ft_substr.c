/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:33:22 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:30:39 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= strlen(s))
		return (strdup(""));
	if (start + len > strlen(s))
		new_s = malloc((strlen(s) - start +1) * sizeof(char));
	else
		new_s = malloc((len +1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[start + i] && start + i < len + start)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
