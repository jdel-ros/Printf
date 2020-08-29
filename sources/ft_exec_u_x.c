/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exec_u_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 19:11:21 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:09:27 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			ft_un_x_flags_m(t_print *print)
{
	if (print->flags == '-')
	{
		if (print->prec != 0)
		{
			print->prec -= ft_strlen(print->typestring);
			while (print->prec > 0 && ++print->ret)
			{
				ft_putchar('0');
				print->prec--;
			}
		}
		ft_putstr(print->typestring);
		print->ret += ft_strlen(print->typestring);
		if (print->width != 0)
		{
			while (print->width > 0 && ++print->ret)
			{
				ft_putchar(' ');
				print->width--;
			}
		}
	}
}

static void			ft_un_x_flags_z(t_print *print, char *str, int i)
{
	if (print->flags == '0' || print->flags == '1')
	{
		if (print->width != 0)
		{
			while (print->width > 0 && ++print->ret)
			{
				if (ft_chrprecstring(str, i) == 0 && print->flags == '0')
					ft_putchar('0');
				else
					ft_putchar(' ');
				print->width--;
			}
		}
		if (print->prec != 0)
		{
			print->prec -= ft_strlen(print->typestring);
			while (print->prec > 0 && ++print->ret)
			{
				ft_putchar('0');
				print->prec--;
			}
		}
		ft_putstr(print->typestring);
		print->ret += ft_strlen(print->typestring);
	}
}

static int			ft_intzero(char *str, t_print *print, int i)
{
	char *s;

	s = ft_strdup(print->typestring);
	if (s[0] == '0' && print->prec == 0 && ft_chrprecstring(str, i) == 1)
	{
		while (print->width > 0 && ++print->ret)
		{
			ft_putchar(' ');
			print->width--;
		}
		free(s);
		s = NULL;
		return (1);
	}
	free(s);
	s = NULL;
	return (0);
}

static int			ft_un_x_casspe(char *str, t_print *print, int j)
{
	if (print->typestring[0] == '0' && ft_chrprecstring(str, j) == 0 &&
		print->width == 0 && ft_ifwidth(str, j) == 0 && print->prec == 0)
	{
		print->ret++;
		ft_putstr(print->typestring);
		free(print->typestring);
		return (0);
	}
	if (print->typestring[0] == '0' && ft_chrprecstring(str, j) == 1 &&
		print->width == 0 && ft_ifwidth(str, j) == 1 && print->prec2 < 0)
	{
		print->ret++;
		ft_putstr(print->typestring);
		free(print->typestring);
		return (0);
	}
	return (1);
}

int					ft_exec_u_x(char *str, t_print *print, int j)
{
	int			i;

	i = 0;
	if (ft_un_x_casspe(str, print, j) == 0)
		return (0);
	if (ft_intzero(str, print, j) == 1)
	{
		free(print->typestring);
		return (0);
	}
	if (print->prec < (int)ft_strlen(print->typestring))
		print->width -= (int)ft_strlen(print->typestring);
	else if (print->prec != 0 && print->width != 0)
		print->width -= print->prec;
	else if (print->prec == 0)
		print->width -= (int)ft_strlen(print->typestring);
	ft_un_x_flags_m(print);
	ft_un_x_flags_z(print, str, j);
	free(print->typestring);
	return (0);
}
