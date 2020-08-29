/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execwidth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 13:59:24 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 12:39:27 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int					ft_execwidth(t_print *print, char *str, int i)
{
	(void)str;
	if (print->width2 == 0 && print->prec2 == 0 && ft_chrprecstring(str, i) == 1
		&& ft_ifwidth(str, i) == 1 && print->lint == 0 &&
		ft_ifwidthetoile(str, i) == 0 && ft_ifprecetoile(str, i) == 0)
		print->ret++;
	if (print->width != 0 && print->typeint < 0 &&
		print->prec2 >= ft_intlen(print->typeint))
		print->width--;
	if (print->width < print->prec2)
	{
		print->width = 0;
		return (0);
	}
	if (print->prec2 < ft_intlen(print->typeint))
		print->width -= (ft_intlen(print->typeint));
	else if (print->width >= print->prec2)
		print->width -= print->prec2;
	if (print->prec2 == 0 && print->typeint == 0 &&
		ft_chrprecstring(str, i) == 1)
		print->width++;
	return (0);
}

int					ft_execwidthfz(t_print *print, char *str, int i)
{
	if (print->typeres == 1)
	{
		ft_execwidth(print, str, i);
		while (print->width > 0 && ++print->ret)
		{
			if (ft_chrprecstring(str, i) == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			print->width--;
		}
		return (0);
	}
	return (0);
}

int					ft_execwidthff(t_print *print, char *str, int i)
{
	if (print->typeres == 1)
	{
		ft_execwidth(print, str, i);
		while (print->width > 0 && ++print->ret)
		{
			if (print->flags == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			print->width--;
		}
		return (0);
	}
	return (0);
}

int					ft_weird(char *str, int i, t_print *print)
{
	if (ft_chrprecstring(str, i) == 1 && print->flags == '0' &&
		print->prec2 < 0)
	{
		if (print->width != 0)
		{
			if (ft_execintneg_two(print) == 1)
			{
				ft_putchar('-');
				print->width -= 1;
				print->ret += 1;
			}
			print->width -= (ft_intlen(print->typeint));
			print->ret += (ft_intlen(print->typeint));
			while (print->width > 0 && ++print->ret)
			{
				ft_putchar('0');
				print->width--;
			}
			ft_putnbr(print->typeint);
			return (1);
		}
		return (0);
	}
	return (0);
}

int					ft_weird_two(char *str, int i, t_print *print)
{
	if (ft_chrprecstring(str, i) == 1 && print->flags == '1' &&
		print->prec2 < 0)
	{
		if (print->width != 0)
		{
			if (ft_execintneg_two(print) == 1)
			{
				ft_putchar('-');
				print->width -= 1;
				print->ret += 1;
			}
			print->width -= (ft_intlen(print->typeint));
			print->ret += (ft_intlen(print->typeint));
			while (print->width > 0 && ++print->ret)
			{
				ft_putchar(' ');
				print->width--;
			}
			ft_putnbr(print->typeint);
			return (1);
		}
		return (0);
	}
	return (0);
}
