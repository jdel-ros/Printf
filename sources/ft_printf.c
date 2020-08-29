/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:26:33 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:32:38 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int			ft_call_ft(char *str, int i, t_print *print, va_list ap)
{
	if (str[i] == '\0')
		return (1);
	ft_flags(str, print, i);
	ft_width(str, print, ap, i);
	ft_precision(str, print, ap, i);
	ft_width_prec_neg(str, print, i);
	print->typeres = ft_rectyperes(str, i);
	ft_rectype(print, str, ap, i);
	ft_exectype(str, print, i);
	return (0);
}

static int			ft_calltxt(char *str, t_print *print, int i)
{
	if (print->typeres != 7)
		print->ret += ft_txtend(print, str, i);
	if (print->typeres == 7)
	{
		print->retpourc = 1;
		i++;
		while (str[i] != '%')
			i++;
	}
	if (print->retpourc == 1)
		print->ret += ft_txtendpourc(print, str, i);
	print->width = 0;
	print->prec = 0;
	print->retpourc = 0;
	return (i);
}

int					ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	t_print		print;

	i = 0;
	va_start(ap, str);
	ft_initvar(&print, str);
	while (str[i])
	{
		i = ft_intchr(str, '%', i);
		if (ft_call_ft((char *)str, i, &print, ap) == 1)
		{
			va_end(ap);
			return (print.ret);
		}
		i = ft_calltxt((char *)str, &print, i);
		i++;
	}
	va_end(ap);
	return (print.ret);
}
