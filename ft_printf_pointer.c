/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:07:28 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 17:54:34 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_no_accuracy(t_print *var, int base, int len, long num)
{
	char space;

	if (var->zero)
		space = '0';
	else
		space = ' ';
	if (len + 2 < var->width)
		var->accuracy = var->width - len - 2;
	else
		var->accuracy = 0;
	if (var->minus)
	{
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
		ft_putnbr_fd(num, base, 0, var);
		ft_put_fd(space, 1, var->accuracy, var);
	}
	else
	{
		ft_put_fd(space, 1, var->accuracy, var);
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
		ft_putnbr_fd(num, base, 0, var);
	}
}

void	ft_pointer_with_accuracy(t_print *var, int base, int len, long num)
{
	if (var->accuracy < len || var->accuracy < 0)
		var->accuracy = len;
	if (var->width > var->accuracy)
		var->width -= 2;
	if (var->width < var->accuracy)
		var->width = var->accuracy;
	if (!var->minus)
	{
		ft_put_fd(' ', 1, var->width - var->accuracy, var);
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
		ft_put_fd('0', 1, var->accuracy - len, var);
		ft_putnbr_fd(num, base, 0, var);
	}
	else
	{
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
		ft_put_fd('0', 1, var->accuracy - len, var);
		ft_putnbr_fd(num, base, 0, var);
		ft_put_fd(' ', 1, var->width - var->accuracy, var);
	}
}

void	ft_output_pointer(t_print *var, int num)
{
	if (!num && var->accuracy == 0 && var->minus == 0 && var->width == 0)
	{
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
	}
	if (!num && var->accuracy == 0 && var->minus == 1 && var->width != 0)
	{
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
		ft_put_fd(' ', 1, var->width - 2, var);
	}
	if (!num && var->accuracy == 0 && var->minus == 0 && var->width != 0)
	{
		ft_put_fd(' ', 1, var->width - 2, var);
		ft_put_fd('0', 1, 1, var);
		ft_put_fd('x', 1, 1, var);
	}
}

void	output_pointer(t_print *var, int base)
{
	long	num;
	int		len;

	num = va_arg(var->output, unsigned long);
	len = ft_num_len(num, base);
	if (var->accuracy < 0)
		ft_pointer_no_accuracy(var, base, len, num);
	else
	{
		if (!num && var->accuracy == 0)
			ft_output_pointer(var, num);
		else if (!num && var->accuracy != 0)
			ft_null_pointer(var);
		else
			ft_pointer_with_accuracy(var, base, len, num);
	}
}
