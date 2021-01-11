/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:11:57 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:31:56 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_print *var)
{
	var->zero = 1;
	var->string++;
}

void	flag_minus(t_print *var)
{
	var->minus = 1;
	var->string++;
}

void	chek_type(t_print *var)
{
	if (*var->string == 'c')
		output_flag_c(var);
	if (*var->string == 's')
		output_flag_s(var);
	if (*var->string == 'p')
		output_pointer(var, 16);
	if (*var->string == 'd' || *var->string == 'i')
		output_number_di(var, 10, 0);
	if (*var->string == 'u')
		output_number_ux(var, 10, 0);
	if (*var->string == 'x')
		output_number_ux(var, 16, 0);
	if (*var->string == 'X')
		output_number_ux(var, 16, 1);
	if (*var->string == '%')
		output_flag_proc(var);
}

void	ft_pars(t_print *var)
{
	while (*var->string != '\0')
	{
		while (*var->string == '0' || *var->string == '-' ||
		*var->string == '*' || *var->string == '.' ||
		(*var->string >= '0' && *var->string <= '9'))
		{
			if (*var->string == '0' || *var->string == '-')
				((*var->string == '0') ? flag_zero(var) : flag_minus(var));
			if (*var->string == '*' || *var->string == '.' ||
			(*var->string >= '0' && *var->string <= '9'))
				((*var->string == '.') ? flag_accuracy(var) : ft_width(var));
		}
		if ((ft_memchr("spcdiuxX%", *var->string, 9)))
		{
			if ((var)->minus == 1)
				(var)->zero = 0;
			chek_type(var);
			(var->string)++;
			break ;
		}
		else
			return ;
	}
}

void	zeroing_var(t_print *var)
{
	var->minus = 0;
	var->zero = 0;
	var->accuracy = -1;
	var->width = 0;
}
