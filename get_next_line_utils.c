/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:59:35 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/19 19:07:44 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*new;
	int		i;
	int		finish;

	i = 0;
	if (!s)
		return (NULL);
	finish = ft_pstrlen(s) - start;
	if (start >= ft_pstrlen(s))
		len = 0;
	else if (finish < len)
		len = finish;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
