/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:00:25 by acase             #+#    #+#             */
/*   Updated: 2020/11/17 21:03:42 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_flag_s(t_print *var)
{
	int		len;
	char	*str;

	str = va_arg(var->output, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (var->accuracy < 0)
		output_s_no_accuracy(len, str, var);
	else
		output_s_with_accuracy(len, str, var);
}

void	output_flag_proc(t_print *var)
{
	char c;
	char space;

	c = '%';
	if (var->zero)
		space = '0';
	else
		space = ' ';
	if (!var->width)
		var->width = 1;
	if (var->minus == 1)
	{
		ft_putchar_fd(c, 1, var);
		ft_put_fd(space, 1, (var->width - 1), var);
	}
	else
	{
		ft_put_fd(space, 1, (var->width - 1), var);
		ft_putchar_fd(c, 1, var);
	}
}

void	output_flag_c(t_print *var)
{
	char c;
	char space;

	c = va_arg(var->output, int);
	if (var->zero)
		space = '0';
	else
		space = ' ';
	if (!var->width)
		var->width = 1;
	if (var->minus == 1)
	{
		ft_putchar_fd(c, 1, var);
		ft_put_fd(space, 1, (var->width - 1), var);
	}
	else
	{
		ft_put_fd(space, 1, (var->width - 1), var);
		ft_putchar_fd(c, 1, var);
	}
}
