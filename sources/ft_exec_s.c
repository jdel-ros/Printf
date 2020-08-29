/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exec_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:02:59 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:27:11 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void				ft_exec_string_two(t_print *print)
{
	int i;

	i = 0;
	if (print->flags == '-')
	{
		while (print->len > 0 && ++print->ret && print->typestring[i])
		{
			ft_putchar(print->typestring[i++]);
			print->len--;
		}
	}
	while (print->width > 0 && ++print->ret)
	{
		ft_putchar(' ');
		print->width--;
	}
	if (print->flags == '1')
	{
		while (print->len > 0 && ++print->ret && print->typestring[i])
		{
			ft_putchar(print->typestring[i++]);
			print->len--;
		}
	}
}

int						ft_exec_string(t_print *print, char *str, int i)
{
	print->len = ft_strlen(print->typestring);
	if (print->len > print->prec && ft_chrprecstring(str, i) == 1)
		print->len = print->prec;
	if (print->prec2 < 0)
		print->len = ft_strlen(print->typestring);
	print->width -= print->len;
	ft_exec_string_two(print);
	free(print->typestring);
	return (0);
}
