/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execpointer.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:04:33 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 11:55:54 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			ft_widthsupp(t_print *print, char *str, int i)
{
	if (ft_chrprecstring(str, i) == 1 && print->typestring[0] == '0' &&
		print->typestring[2] == '0' && print->typestring[3] == '\0')
		print->typestring[2] = '\0';
	print->width -= ft_strlen(print->typestring);
	if (print->flags == '1')
	{
		while (print->width > 0 && ++print->ret)
		{
			ft_putchar(' ');
			print->width--;
		}
	}
	ft_putstr(print->typestring);
	print->ret += (int)ft_strlen(print->typestring);
	if (print->flags == '-')
	{
		while (print->width > 0 && ++print->ret)
		{
			ft_putchar(' ');
			print->width--;
		}
	}
}

int					ft_execpointer(t_print *print, char *str, int i)
{
	if (ft_ifwidth(str, i) == 0 && ft_chrprecstring(str, i)
		&& print->typestring[2] == '0' && print->prec == 0)
	{
		print->ret += ((int)ft_strlen(print->typestring) - 1);
		ft_putstr("0x");
		free(print->typestring);
		return (0);
	}
	if (ft_ifwidth(str, i) == 0)
		print->width = 0;
	if (print->width > 0)
		ft_widthsupp(print, str, i);
	else
	{
		ft_putstr(print->typestring);
		print->ret += (int)ft_strlen(print->typestring);
	}
	free(print->typestring);
	return (0);
}
