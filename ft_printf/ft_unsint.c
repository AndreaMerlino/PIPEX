/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:10 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:04:12 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsint(unsigned int a)
{
	int	i;

	i = 0;
	if (a > 9)
		i += ft_unsint(a / 10);
	i ++;
	a = a % 10;
	a += 48;
	write(1, &a, 1);
	return (i);
}
