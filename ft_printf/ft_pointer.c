/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:02:28 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:02:30 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long x)
{
	int	i;

	i = 2;
	write (1, "0", 1);
	write (1, "x", 1);
	i += ft_puthex(x);
	return (i);
}
