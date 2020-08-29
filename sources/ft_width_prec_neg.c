/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width_prec_neg.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 17:37:34 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 12:39:37 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			ft_width_prec_neg(char *str, t_print *print, int i)
{
	if (print->width < 0)
	{
		print->width *= -1;
		print->flags = '-';
		if (print->flags == '0' && ft_chrprecstring(str, i) == 1)
			print->prec *= -1;
		else if (print->flags == '0' && ft_chrprecstring(str, i) == 0)
			print->flags = '-';
	}
	if (print->prec < 0)
	{
		print->prec *= -1;
		if (print->flags == '1')
			print->flags = '-';
		else if (print->flags == '0' && ft_chrprecstring(str, i) == 1)
			print->prec *= -1;
		else if (print->flags == '0' && ft_chrprecstring(str, i) == 0)
			print->flags = '-';
	}
}

int				ft_execwidthneg(t_print *print, char *str, int i)
{
	ft_execwidth(print, str, i);
	while (print->width > 0 && ++print->ret)
	{
		ft_putchar(' ');
		print->width--;
	}
	return (0);
}
