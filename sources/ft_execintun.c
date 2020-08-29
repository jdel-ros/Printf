/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execintun.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:49:16 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 15:37:34 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_intprecinf(t_print *print)
{
	ft_putnbr(print->lint);
	if (print->lint == 0)
		print->ret++;
	return (0);
}

int			ft_intprecspe(t_print *print)
{
	if (print->width2 != 0)
		print->ret--;
	return (0);
}
