/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execprec.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 14:44:40 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/05 11:34:39 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_execprec(Print *print)
{
	if (print->prec != 0)
	{
		if (print->typeres == 1)
			print->prec -= ft_intlen(print->typeint);
		while (print->prec > 0 && ++print->ret)
		{
			ft_putchar('0');
			print->prec--;
		}
	}
	return (0);
}
