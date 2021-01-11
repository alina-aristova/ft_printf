/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:06:57 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:23:25 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_num_len(long n, int base)
{
	long	len;

	len = 0;
	while (n > base - 1 || n < -(base - 1))
	{
		len++;
		n /= base;
	}
	len++;
	if (n < 0)
		len++;
	return (len);
}

void	ft_num_minus(t_print *var)
{
	if (var->num < 0)
	{
		ft_putchar_fd('-', 1, var);
		var->num = -(var->num);
	}
}

void	ft_num(t_print *var, long num)
{
	if (num < 0)
	{
		var->accuracy++;
		if (var->width < var->accuracy)
			var->width++;
	}
}
