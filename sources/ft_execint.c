/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 18:58:32 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:54:00 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int				ft_precinf(char *str, t_print *print, int i)
{
	if (ft_chrprecstring(str, i) == 1 && print->lint == 0 &&
		print->prec >= 0 && print->width == 0)
	{
		print->ret--;
		while (print->prec > 0 && ++print->ret)
		{
			ft_putchar('0');
			print->prec--;
		}
	}
	if (ft_chrprecstring(str, i) == 1 && print->lint < 0 &&
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

static int				ft_intflagsm(char *str, t_print *print, int i)
{
	if (ft_execintneg(print) == 1)
	{
		ft_putchar('-');
		print->prec += 1;
	}
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprecstring(str, i) == 1 && print->lint == 0)
		print->ret--;
	else
		ft_putnbr(print->lint);
	ft_execwidthff(print, str, i);
	return (0);
}

static int				ft_intflagsz(char *str, t_print *print, int i)
{
	if (ft_execintneg(print) == 1)
	{
		if (ft_chrprecstring(str, i) == 0)
			ft_putchar('-');
		ft_execwidthfz(print, str, i);
		if (ft_chrprecstring(str, i) == 1)
			ft_putchar('-');
		print->prec++;
		ft_execprec(print);
		ft_putnbr(print->lint);
		return (0);
	}
	ft_execwidthfz(print, str, i);
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprecstring(str, i) == 1 && print->lint == 0)
		print->ret--;
	if (print->lint == 0 && ft_chrprecstring(str, i) == 1 && print->width2 == 0)
		return (0);
	if (print->lint == 0 && ft_chrprecstring(str, i) == 1 && print->prec2 == 0)
		return (0);
	else
		ft_putnbr(print->lint);
	return (0);
}

static int				ft_intun(char *str, t_print *print, int i)
{
	if (print->width2 == 0 && print->prec2 == 0 && print->typeint == 0
		&& ft_chrprecstring(str, i) == 0 && ft_chrprecstring(str, i) == 1)
	{
		print->ret--;
		return (0);
	}
	if (ft_execintneg(print) == 1)
	{
		print->prec++;
		ft_execwidthneg(print, str, i);
		ft_putchar('-');
		ft_execprec(print);
		ft_putnbr(print->lint);
		return (0);
	}
	if (print->prec2 < 0)
		return (ft_intprecinf(print));
	ft_execwidthff(print, str, i);
	ft_execprec(print);
	if (print->prec2 == 0 && ft_chrprecstring(str, i) == 1 && print->lint == 0)
		return (ft_intprecspe(print));
	if (!(print->lint == 0 && ft_chrprecstring(str, i) == 1
			&& print->width2 == 0))
		ft_putnbr(print->lint);
	return (0);
}

int						ft_execint(char *str, t_print *print, int i)
{
	if (ft_weird(str, i, print) == 1 || ft_weird_two(str, i, print) == 1)
		return (0);
	if (print->prec2 < 0 && print->width == 0 &&
		ft_ifwidth(str, i) == 1 && print->typeint == 0)
	{
		print->prec2 = 0;
		ft_putchar('0');
		print->ret += 2;
		if (ft_ifwidthetoile(str, i) == 1)
			print->ret--;
	}
	print->lint = print->typeint;
	print->ret += ft_intlen(print->lint);
	print->width2 = print->width;
	if (print->prec2 >= 0)
		print->prec2 = print->prec;
	ft_precinf(str, print, i);
	if (print->flags == '-')
		return (ft_intflagsm(str, print, i));
	if (print->flags == '0')
		return (ft_intflagsz(str, print, i));
	if (print->flags == '1')
		return (ft_intun(str, print, i));
	return (0);
}
