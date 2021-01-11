/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:07:57 by acase             #+#    #+#             */
/*   Updated: 2020/11/18 16:49:21 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_print
{
	va_list	output;
	char	*string;
	int		zero;
	int		minus;
	int		accuracy;
	int		width;
	int		rez_len;
	long	num;
}				t_print;

int				ft_printf(const char *str, ...);
void			output_flag_c(t_print *var);
int				ft_strlen(char *str);
void			output_flag_s(t_print *var);
void			output_flag_proc(t_print *var);
void			ft_putchar_fd(char c, int fd, t_print *var);
void			output_flag_s(t_print *var);
void			output_flag_proc(t_print *var);
void			output_flag_c(t_print *var);
void			flag_accuracy(t_print *var);
void			ft_width(t_print *var);
void			ft_put_fd(char s, int fd, int size, t_print *var);
int				ft_atoi(char *str);
void			output_s_no_accuracy(int len, char *str, t_print *var);
void			output_s_with_accuracy(int len, char *str, t_print *var);
void			output_number_di(t_print *var, int base, int upper);
void			output_number_ux(t_print *var, int base, int upper);
void			output_pointer(t_print *var, int base);
long			ft_num_len(long n, int base);
void			ft_putchar_fd(char c, int fd, t_print *var);
void			ft_putnbr_fd(long n, size_t base, int up, t_print *var);
void			ft_put_fd(char s, int fd, int size, t_print *var);
void			ft_putstr_fd(char *s, int fd, int len, t_print *var);
void			ft_null_pointer(t_print *var);
long			ft_num_len(long n, int base);
void			ft_num_minus(t_print *var);
void			ft_num(t_print *var, long num);
void			zeroing_var(t_print *var);
void			ft_pars(t_print *var);
void			*ft_memchr(void *s, int c, size_t n);
void			ft_null_pointer(t_print *var);

#endif
