/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:32:06 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:37:23 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_with_accuracy(t_print *var, int base, int upper, int len)
{
	if (len <= var->accuracy)
		ft_num(var, var->num);
	if (var->accuracy < len)
		var->accuracy = len;
	if (var->width < var->accuracy)
		var->width = var->accuracy;
	if (!var->minus)
	{
		ft_put_fd(' ', 1, var->width - var->accuracy, var);
		ft_num_minus(var);
		ft_put_fd('0', 1, (var->accuracy - len), var);
		ft_putnbr_fd(var->num, base, upper, var);
	}
	else
	{
		ft_num_minus(var);
		ft_put_fd('0', 1, var->accuracy - len, var);
		ft_putnbr_fd(var->num, base, upper, var);
		ft_put_fd(' ', 1, var->width - var->accuracy, var);
	}
}

void	num_no_accuracy(t_print *var, int base, int upper, int len)
{
	char spase;

	if (var->zero)
	{
		spase = '0';
		ft_num_minus(var);
	}
	else
		spase = ' ';
	if (len < var->width)
		var->accuracy = var->width - len;
	else
		var->accuracy = 0;
	if (!var->minus)
	{
		ft_put_fd(spase, 1, var->accuracy, var);
		ft_num_minus(var);
		ft_putnbr_fd(var->num, base, upper, var);
	}
	else
	{
		ft_putnbr_fd(var->num, base, upper, var);
		ft_put_fd(spase, 1, var->accuracy, var);
	}
}

void	output_number_di(t_print *var, int base, int upper)
{
	int len;

	var->num = va_arg(var->output, int);
	len = ft_num_len(var->num, base);
	if (var->accuracy < 0)
	{
		num_no_accuracy(var, base, upper, len);
	}
	else
	{
		if (!var->num && var->accuracy == 0)
			ft_put_fd(' ', 1, var->width, var);
		else
			num_with_accuracy(var, base, upper, len);
	}
}

void	output_number_ux(t_print *var, int base, int upper)
{
	long len;

	var->num = va_arg(var->output, unsigned int);
	len = ft_num_len(var->num, base);
	if (var->accuracy < 0)
	{
		num_no_accuracy(var, base, upper, len);
	}
	else
	{
		if (!var->num && var->accuracy == 0)
			ft_put_fd(' ', 1, var->width, var);
		else
			num_with_accuracy(var, base, upper, len);
	}
}
