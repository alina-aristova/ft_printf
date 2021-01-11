/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:25:37 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:27:42 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_s_no_accuracy(int len, char *str, t_print *var)
{
	char space;

	space = (!var->zero ? ' ' : '0');
	if (len < var->width)
	{
		var->accuracy = var->width - len;
	}
	else
		var->accuracy = 0;
	if (!(var->minus))
	{
		ft_put_fd(space, 1, var->accuracy, var);
		ft_putstr_fd(str, 1, len, var);
	}
	else
	{
		ft_putstr_fd(str, 1, len, var);
		ft_put_fd(space, 1, var->accuracy, var);
	}
}

void	output_s_with_accuracy(int len, char *str, t_print *var)
{
	char space;

	space = (!var->zero ? ' ' : '0');
	if ((len < var->accuracy || var->accuracy < 0))
		var->accuracy = len;
	if (var->width < var->accuracy)
		var->width = var->accuracy;
	if (!var->minus)
	{
		ft_put_fd(space, 1, var->width - var->accuracy, var);
		ft_putstr_fd(str, 1, var->accuracy, var);
	}
	else
	{
		ft_putstr_fd(str, 1, var->accuracy, var);
		ft_put_fd(space, 1, var->width - var->accuracy, var);
	}
}
