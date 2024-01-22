/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:02:57 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/21 20:03:00 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		bytes;

	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	while (bytes--)
		((char *)ptr)[bytes] = 0;
	return (ptr);
}

int	ft_pstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strlcpy(char *dst, char *src, int dstsize)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)src;
	while ((i < dstsize - 1) && (*s != '\0'))
	{
		*dst++ = *s++;
		i++;
	}
	*dst = '\0';
	return (s - i);
}

char	*ft_strlcat(char *dst, char *src, int dstsize)
{
	int	lendst;

	if (!dst && !src)
		return (0);
	lendst = ft_pstrlen(dst);
	dst = ft_strlcpy((dst + lendst), src, (dstsize));
	return (dst - lendst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
