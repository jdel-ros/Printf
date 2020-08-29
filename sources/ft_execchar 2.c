/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:42:32 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 13:30:55 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int		ft_charflagsm(Print *print)
{
	if (print->flags == '-')
	{
		while (print->width > 0 && ++print->ret)
		{
			ft_putchar(' ');
			print->width--;
		}
	}
	return (0);
}

int				ft_execchar(Print *print)
{
	if (print->width != 0)
	{
		print->width -= 1;
		if (print->flags == '1')
		{
			while (print->width > 0 && ++print->ret)
			{
				ft_putchar(' ');
				print->width--;
			}
		}
		ft_putchar(print->typeint);
		print->ret += 1;
		ft_charflagsm(print);
	}
	else
	{
		ft_putchar(print->typeint);
		print->ret += 1;
	}
	return (0);
}
