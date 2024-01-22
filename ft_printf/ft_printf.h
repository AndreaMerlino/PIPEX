/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by andreamerli       #+#    #+#             */
/*   Updated: 2023/11/20 11:03:50 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int	ft_pointer(unsigned long x);
int	ft_printf(const char *p, ...);
int	ft_putchar(char c);
int	ft_putdigit(int a);
int	ft_putstr(char *str);
int	ft_unsint(unsigned int a);
int	ft_puthex(unsigned int x);
int	ft_putxx(unsigned int x);
#endif
