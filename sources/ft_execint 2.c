/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 18:58:32 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 16:56:26 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int				ft_precinf(char *str, Print *print)
{
	if (ft_chrprec(str) == 1 && print->lint == 0 &&
		print->prec >= 0 && print->width == 0)
	{
		print->ret--;
		while (print->prec > 0 && ++print->ret)
		{
			ft_putchar('0');
			print->prec--;
		}
	}
	if (ft_chrprec(str) == 1 && print->lint < 0 &&
		print->prec >= ft_intlen(print->lint + 1) && print->width == 0)
	{
		if (ft_execintneg(print) == 1)
		{
			ft_putchar('-');
			print->prec -= ft_intlen(print->lint);
		}
		while (print->prec > 0 && ++print->ret)
		{
			ft_putchar('0');
			print->prec--;
		}
	}
	return (0);
}

static int				ft_intflagsm(char *str, Print *print)
{
	if (ft_execintneg(print) == 1)
	{
		ft_putchar('-');
		print->prec += 1;
	}
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprec(str) == 1 && print->lint == 0)
		print->ret--;
	else
		ft_putnbr(print->lint);
	ft_execwidthfm(print, str);
	return (0);
}

static int				ft_intflagsz(char *str, Print *print)
{
	if (ft_execintneg(print) == 1)
	{
		if (ft_chrprec(str) == 0)
			ft_putchar('-');
		ft_execwidthfz(print, str);
		if (ft_chrprec(str) == 1)
			ft_putchar('-');
		print->prec++;
		ft_execprec(print);
		ft_putnbr(print->lint);
		return (0);
	}
	ft_execwidthfz(print, str);
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprec(str) == 1 && print->lint == 0)
		print->ret--;
	else
		ft_putnbr(print->lint);
	return (0);
}

static int				ft_intun(char *str, Print *print)
{
	if (print->width2 == 0 && print->prec2 == 0 && print->typeint == 0
		&& ft_chrprec(str) == 0 && ft_chrprecint(str) == 1)
	{
		print->ret--;
		return (0);
	}
	if (ft_execintneg(print) == 1)
	{
		print->prec++;
		ft_execwidthneg(print, str);
		ft_putchar('-');
		ft_execprec(print);
		ft_putnbr(print->lint);
		return (0);
	}
	if (print->prec2 < 0)
	{
		ft_putnbr(print->lint);
		if (print->lint == 0)
			print->ret++;
		return (0);
	}
	ft_execwidthff(print, str);
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprec(str) == 1 && print->lint == 0)
	{
		if (print->width2 != 0)
			print->ret--;
		return (0);
	}
	if (!(print->lint == 0 && ft_chrprec(str) == 1 && print->width2 == 0))
		ft_putnbr(print->lint);
	return (0);
}

int						ft_execint(char *str, Print *print, int i)
{
	(void)str;
	if (print->prec2 < 0 && print->width == 0 &&
		ft_ifwidth(str, i) == 1 && print->typeint == 0)
	{
		print->prec2 = 0;
		ft_putchar('0');
		print->ret += 2;
	}
	print->lint = print->typeint;
	print->ret += ft_intlen(print->lint);
	print->width2 = print->width;
	if (print->prec2 >= 0)
		print->prec2 = print->prec;
	ft_precinf(str, print);
	if (print->flags == '-')
		return (ft_intflagsm(str, print));
	if (print->flags == '0')
		return (ft_intflagsz(str, print));
	if (print->flags == '1')
		return (ft_intun(str, print));
	return (0);
}
