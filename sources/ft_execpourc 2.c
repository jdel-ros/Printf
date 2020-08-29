/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execpourc.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:02:42 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:41:38 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int			ft_pourcflagsm(Print *print)
{
	if (print->flags == '-')
	{
		print->width -= 1;
		printf("OUI");
		dprintf(1, "\n|||%d|||\n", print->width);
		while (print->width > 0 && ++print->ret)
		{
			ft_putchar(' ');
			print->width--;
		}
	}
	return (0);
}

static int			ft_pourcflagsz(Print *print)
{
	if (print->flags == '0' || print->flags == '1')
	{
		print->width -= 1;
		while (print->width > 0)
		{
			if (print->flags == '0')
			{
				ft_putchar('0');
				print->ret++;
			}
			else if (print->flags == '1')
			{
				ft_putchar(' ');
				print->ret++;
			}
			print->width--;
		}
	}
	return (0);
}

int					ft_execpourc(Print *print)
{
	if (print->typeres == 7)
		print->typeint = 37;
	ft_pourcflagsz(print);
	ft_putchar(print->typeint);
	print->ret++;
	ft_pourcflagsm(print);
	return (0);
}
