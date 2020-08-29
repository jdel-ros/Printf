/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 12:35:27 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 14:45:29 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void				ft_type_sp(t_print *print, char *str, int i, va_list ap)
{
	unsigned long		d;
	char				*s;

	while (str[i] != 'p' || str[i] != 's' || str[i] != '\0')
	{
		if (str[i] == 'p')
		{
			d = va_arg(ap, unsigned long);
			print->typestring = ft_strdup("0x");
			print->typestring = ft_strjoin(print->typestring,
								ft_utoa_base(d, "0123456789abcdef"));
			return ;
		}
		if (str[i] == 's')
		{
			s = va_arg(ap, char *);
			if (s == NULL)
				print->typestring = ft_strdup("(null)");
			else
				print->typestring = ft_strdup(s);
			return ;
		}
		i++;
	}
}

void				ft_type_cdi(t_print *print, char *str, int i, va_list ap)
{
	int				d;

	while (str[i] != 'c' || str[i] != 'd' || str[i] != 'i' || str[i] != '\0')
	{
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i')
		{
			d = va_arg(ap, int);
			print->typeint = d;
			return ;
		}
		i++;
	}
}

void				ft_type_xxu(t_print *print, char *str, int i, va_list ap)
{
	unsigned int	d;

	while (str[i] != 'x' || str[i] != 'X' || str[i] != 'u' || str[i] != '\0')
	{
		if (str[i] == 'x')
		{
			d = va_arg(ap, unsigned int);
			print->typestring = ft_itoa_base(d, "0123456789abcdef");
			return ;
		}
		else if (str[i] == 'X')
		{
			d = va_arg(ap, unsigned long);
			print->typestring = ft_itoa_base(d, "0123456789ABCDEF");
			return ;
		}
		else if (str[i] == 'u')
		{
			d = va_arg(ap, unsigned int);
			print->typestring = ft_utoa(d);
			return ;
		}
		i++;
	}
}
