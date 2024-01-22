/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:02:53 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:02:58 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cheker(const char str, va_list args)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += ft_putchar ((char)va_arg(args, int));
	else if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		i += ft_pointer((unsigned long)va_arg(args, unsigned long));
	else if (str == 'd' || str == 'i')
		i += ft_putdigit(va_arg(args, int));
	else if (str == 'u')
		i += ft_unsint(va_arg(args, unsigned int));
	else if (str == 'x')
		i += ft_puthex(va_arg(args, unsigned int));
	else if (str == 'X')
		i += ft_putxx(va_arg(args, unsigned long));
	else if (str == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *p, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, p);
	if (!p)
		return (0);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			count += ft_cheker(*p, args);
		}
		else
			count += write (1, p, 1);
		p++;
	}
	va_end(args);
	return (count);
}
