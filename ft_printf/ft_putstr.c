/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:03 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:04:05 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, i);
	return (i);
}
