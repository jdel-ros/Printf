/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:26:33 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:38:15 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			j;
	Print		print;

	i = 0;
	j = 0;
	va_start(ap, str);
	ft_initvar(&print, str);
	j = print.ret;
	if (j == (int)ft_strlen(str))
		return (j);
	j = 0;
	while (str[i])
	{
		i = ft_intchr(str, '%', i);
		if (str[i] == '\0')
			return (print.ret);
		ft_flags((char *)str, &print, i);
		ft_width((char *)str, &print, ap, i);
		if (print.width < 0)
		{
		print.width *= -1;
		if (print.flags == '1')
			print.flags = '-';
		else if (print.flags == '0' && ft_chrprec((char*)str) == 1)
			print.prec *= -1;
		else if (print.flags == '0' && ft_chrprec((char*)str) == 0)
			print.flags = '-';
		}	
		ft_precision((char *)str, &print, ap, i);
		if (print.prec < 0)
		{
		print.prec *= -1;
		if (print.flags == '1')
			print.flags = '-';
		else if (print.flags == '0' && ft_chrprec((char*)str) == 1)
			print.prec *= -1;
		else if (print.flags == '0' && ft_chrprec((char*)str) == 0)
			print.flags = '-';
		}
		print.typeres = ft_rectyperes((char *)str, i);
		ft_rectypestring(&print, (char *)str, ap, i);
		print.typeint = ft_rectypeint(&print, (char *)str, ap, i);
		ft_exectype((char *)str, &print, i);
		if (print.typeres != 7)
			print.ret += ft_txtend((char *)str, i);
		if (print.typeres == 7)
		{
			print.retpourc = 1;
			i++;
			while (str[i] != '%')
				i++;
		}
		if (print.retpourc == 1)
			print.ret += ft_txtendpourc((char*)str);
		i++;
	}
	if (print.typeint < 0 && print.prec >= ft_intlen(print.typeint)
		&& print.width <= ft_intlen(print.typeint))
		print.ret += 1;
	va_end(ap);
	return (print.ret);
}
