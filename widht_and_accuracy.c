/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widht_and_accuracy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:09:45 by acase             #+#    #+#             */
/*   Updated: 2020/11/17 21:06:16 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_accuracy(t_print *var)
{
	if (*(++(var->string)) == '*')
	{
		var->accuracy = (va_arg(var->output, int));
		var->string++;
	}
	else
	{
		var->accuracy = ((ft_atoi(var->string)));
		while ((*(var->string) >= '0' && (*(var->string) <= '9')))
		{
			var->string++;
		}
	}
}

void	ft_width(t_print *var)
{
	if (*var->string == '*')
	{
		var->width = (va_arg(var->output, int));
		var->string++;
		if (var->width < 0)
		{
			var->width = -var->width;
			var->minus = 1;
		}
	}
	else
	{
		var->width = ((ft_atoi(var->string)));
		while (((*var->string) >= '0' && (*var->string) <= '9'))
			var->string++;
	}
}
