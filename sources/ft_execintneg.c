/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execintneg.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 13:05:09 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:16:00 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_execintneg(t_print *print)
{
	if (print->lint < 0)
		if (print->flags == '1' || print->flags == '0' || print->flags == '-')
		{
			print->lint = print->lint * -1;
			return (1);
		}
	return (0);
}

int			ft_execintneg_two(t_print *print)
{
	if (print->typeint < 0)
		if (print->flags == '1' || print->flags == '0' || print->flags == '-')
		{
			print->typeint = print->typeint * -1;
			return (1);
		}
	return (0);
}
