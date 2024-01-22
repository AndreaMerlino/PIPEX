/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:00 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:04:02 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int x)
{
	int	i;

	i = 0;
	if (x > 15)
		i += ft_puthex(x / 16);
	x = x % 16;
	if (x > 9)
		x = 102 - (15 - x);
	else
		x = x + 48;
	i++;
	write(1, &x, 1);
	return (i);
}
