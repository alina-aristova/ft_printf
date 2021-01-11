/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:25:00 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:40:37 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_print var;

	var.rez_len = 0;
	var.string = (char*)str;
	va_start(var.output, str);
	while (*var.string != '\0')
	{
		while (*var.string != '%' && *var.string != '\0')
		{
			write(1, var.string, 1);
			(var.string)++;
			(var.rez_len)++;
		}
		if (*var.string == '%')
			(var.string)++;
		zeroing_var(&var);
		ft_pars(&var);
	}
	va_end(var.output);
	return (var.rez_len);
}
