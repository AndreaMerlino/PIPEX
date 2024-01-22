/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:03:24 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/21 20:03:26 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

void	decl(size_t *i, size_t *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**new;

	if (!s)
		return (NULL);
	new = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	decl(&i, &j, &index);
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			new[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
