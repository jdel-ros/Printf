/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 12:35:27 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 16:24:42 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void				ft_type_spu(Print *print, char *str, int i, va_list ap)
{
	while (str[i] != 's' || str[i] != 'p' || str[i] != 'u')
	{
		if (str[i] == 's')
		{
			char *s;

			s = va_arg(ap, char *);
			if (s == NULL)
				print->typestring = ft_strdup("(null)");
			else
				print->typestring = ft_strdup(s);
			return ;
		}
		if (str[i] == 'p')
		{
			unsigned long d;

			d = va_arg(ap, unsigned long);
			print->typestring = ft_strdup("0x");
			print->typestring = ft_strjoin(print->typestring, ft_utoa_base(d, "0123456789abcdef"));
			return ;
		}
		if (str[i] == 'u')
		{
			unsigned long u;

			u = va_arg(ap, unsigned long);
			print->typestring =  ft_utoa(u);
			return ;
		}
		i++;
	}
	return ;
}

int				ft_type_cdi(char *str, int i, va_list ap)
{
	int				d;

	while (str[i] != 'c' || str[i] != 'd' || str[i] != 'i')
	{
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i')
		{
			d = va_arg(ap, int);
			return (d);
		}
		i++;
	}
	return (0);
}

void				ft_type_xx(Print *print, char *str, int i, va_list ap)
{
	unsigned long	d;

	while (str[i]  != 'x' || str[i] != 'X')
	{
		if (str[i] == 'x')
		{
			d = va_arg(ap, unsigned long);
			print->typestring = ft_itoa_base(d, "0123456789abcdef");
			return ;
		}
		if (str[i] == 'X')
		{
			d = va_arg(ap, unsigned long);
			print->typestring = ft_itoa_base(d, "0123456789ABCDEF");
			return ;
		}
		i++;
	}
	return ;
}
