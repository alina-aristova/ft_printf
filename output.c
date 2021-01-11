/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:59:40 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:43:26 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_print *var)
{
	write(fd, &c, 1);
	var->rez_len++;
}

void	ft_putnbr_fd(long n, size_t base, int up, t_print *var)
{
	char			c;
	unsigned long	num;
	char			upper;

	upper = (up == 1) ? 'A' : 'a';
	if (n < 0)
	{
		write(1, "-", 1);
		var->rez_len++;
		n = -n;
	}
	num = (unsigned long)n;
	if (num >= base)
	{
		ft_putnbr_fd(num / base, base, up, var);
		c = (num % base) + (num % base > 9 ? upper - 10 : '0');
		write(1, &c, 1);
		var->rez_len++;
	}
	if (num >= 0 && num <= base - 1)
	{
		c = num + (num % base > 9 ? upper - 10 : '0');
		write(1, &c, 1);
		var->rez_len++;
	}
}

void	ft_put_fd(char s, int fd, int size, t_print *var)
{
	while (size)
	{
		write(fd, &s, 1);
		var->rez_len++;
		size--;
	}
}

void	ft_putstr_fd(char *s, int fd, int len, t_print *var)
{
	write(fd, s, len);
	var->rez_len = var->rez_len + len;
}
