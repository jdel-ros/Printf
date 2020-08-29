/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_chrprec.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/05 15:33:56 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:22:20 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_chrprec(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if ((str[i + 1] >= 48 && str[i + 1] <= 57) || str[i + 1] == '*')
				return (1);
		i++;
	}
	return (0);
}

int			ft_chrprecstring(char *str, int i)
{
	while (str[i])
	{
		i++;
		if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u' ||
			str[i] == 'p' || str[i] == 'x' || str[i] == 'X' ||
			str[i] == 'i' || str[i] == 'c')
			return (0);
		if (str[i] == '%')
			return (0);
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int			ft_chrprecint(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[i])
			{
				if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
					return (0);
				if (str[i] == '.')
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}
