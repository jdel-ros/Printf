/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_txt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:27:04 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:31:35 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int						ft_txt(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (i);
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int						ft_txtendpourc(t_print *print, char *str, int i)
{
	int j;

	j = 0;
	i++;
	if (print->txtend == 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			return (j);
		if (print->typeres == 7)
			ft_putchar(str[i]);
		i++;
		j++;
	}
	print->txtend = 1;
	return (j);
}

static int				ft_helptxt(t_print *print, char *str, int i, int count)
{
	while (str[i] != '%')
	{
		i++;
		if (str[i] == '\0')
		{
			print->txtend = 1;
			return (count);
		}
		if (str[i] == '%')
			return (count);
		count++;
		ft_putchar(str[i]);
	}
	return (count);
}

int						ft_txtend(t_print *print, char *str, int i)
{
	int				count;

	count = 0;
	while (str[i] != '%')
	{
		if (str[i] == '\0')
			return (count);
		i++;
	}
	while (str[i])
	{
		if (ft_chr_type(str, i) == 0)
			return (ft_helptxt(print, str, i, count));
		i++;
	}
	return (count);
}
