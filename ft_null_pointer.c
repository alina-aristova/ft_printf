/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:09:30 by acase             #+#    #+#             */
/*   Updated: 2020/11/17 21:11:12 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_minus(t_print *var)
{
	ft_put_fd('0', 1, 1, var);
	ft_put_fd('x', 1, 1, var);
	ft_put_fd('0', 1, var->accuracy, var);
	ft_put_fd(' ', 1, var->width - var->accuracy - 2, var);
}

void	null_no_minus(t_print *var)
{
	ft_put_fd(' ', 1, var->width - var->accuracy - 2, var);
	ft_put_fd('0', 1, 1, var);
	ft_put_fd('x', 1, 1, var);
	ft_put_fd('0', 1, var->accuracy, var);
}

void	ft_null_pointer(t_print *var)
{
	if (!var->width)
		var->width = 2;
	if (var->accuracy < 0)
		var->accuracy = 1;
	if (var->width < var->accuracy + 2)
		var->width = var->accuracy + 2;
	((var->minus == 1) ? null_minus(var) : null_no_minus(var));
}
