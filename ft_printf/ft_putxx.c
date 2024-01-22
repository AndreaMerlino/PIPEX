/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:07 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:04:08 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putxx(unsigned int x)
{
	int	i;

	i = 0;
	if (x > 15)
		i += ft_putxx(x / 16);
	x = x % 16;
	if (x > 9)
		x = 70 - (15 - x);
	else
		x = x + 48;
	i++;
	write(1, &x, 1);
	return (i);
}
