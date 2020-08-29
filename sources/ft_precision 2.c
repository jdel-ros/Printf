/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:04:39 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:05:45 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int				ft_ifetoileprec(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i' ||
			str[i] == 's' || str[i] == 'p' || str[i] == 'x' ||
			str[i] == 'X' || str[i] == 'u')
			return (0);
		if (str[i] == '.')
		{
			if (str[i + 1] == '*')
				return (1);
		}
		i++;
	}
	return (0);
}

static int				ft_preclen(char *str, int i)
{
	int				len;

	len = 0;
	while (str[i] != '.')
	{
		if (str[i] == 'd' || str[i] == 's' || str[i] == 'u' ||
		str[i] == 'p' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == 'i' || str[i] == 'c')
			return (len);
		if (str[i] == '\0')
			return (len);
		i++;
	}
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 's' || str[i] == 'u' ||
		str[i] == 'p' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == 'i' || str[i] == 'c')
			return (len);
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			len++;
		}
		else
			i++;
	}
	return (len);
}

void					ft_precision(char *str, Print *print, va_list ap, int i)
{
	char		*precstring2;
	char		*s;
	int			len;
	int			j;

	j = 0;
	len = ft_preclen(str, i);
	if (ft_ifetoileprec(str, i) == 1)
	{
		print->prec = va_arg(ap, int);
		if (print->prec < 0)
		{
			print->prec2 = print->prec;
			print->prec = 0;
		}
		return ;
	}
	if (len != 0)
	{
		if (!(precstring2 = (char *)malloc(sizeof(char) * (len + 1))))
			return ;
		precstring2[len] = '\0';
		s = ft_strdup(str);
		while (s[i] != '.')
			i++;
		while (s[i])
		{
			if (s[i] == 'd' || s[i] == 's' || s[i] == 'u' ||
			s[i] == 'p' || s[i] == 'x' || s[i] == 'X' ||
			s[i] == 'i' || s[i] == 'c')
			{
				print->prec = ft_atoi_printf(precstring2);
				free(s);
				free(precstring2);
				return ;
			}
			if (s[i] >= 48 && s[i] <= 57)
				precstring2[j++] = s[i++];
			else
				i++;
		}
	}
}
