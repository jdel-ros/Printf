/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_chrprec.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/05 15:33:56 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:12:59 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int					ft_chrprecstring(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		if (ft_chr_type(str, i) == 0)
			return (0);
		if (str[i] == '%')
			return (0);
		if (str[i] == '*')
		{
			if (str[i + 1] == '.')
				return (1);
			else
				return (0);
		}
		if (str[i] == '%')
			return (0);
		i++;
	}
	return (0);
}

int					ft_ifwidth(char *str, int i)
{
	if (str[i] == '%')
	{
		i++;
		while (str[i])
		{
			if (ft_chr_type(str, i) == 0)
				return (0);
			if (str[i] == '.')
				return (0);
			if (str[i] == '%')
				return (0);
			if (str[i] == '*')
				return (1);
			if (str[i] >= '0' && str[i] <= '9')
				return (1);
			i++;
		}
	}
	return (0);
}

int					ft_ifprecetoile(char *str, int i)
{
	while (str[i])
	{
		if (ft_chr_type(str, i) == 0)
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

int					ft_ifwidthetoile(char *str, int i)
{
	while (str[i])
	{
		if (ft_chr_type(str, i) == 0)
			return (0);
		if (str[i] == '.')
			return (0);
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

int					ft_chr_type(char *str, int i)
{
	if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i' ||
		str[i] == 's' || str[i] == 'p' || str[i] == 'x' ||
		str[i] == 'X' || str[i] == 'u')
		return (0);
	return (1);
}
