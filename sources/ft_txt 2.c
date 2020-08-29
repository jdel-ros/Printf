/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_txt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:27:04 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:37:43 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int					ft_txt(char *str)
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

int				ft_txtendpourc(char *str)
{
	int i;
	int j;

	i = (int)ft_strlen(str);
	j = 0;
	while (str[i] != '%')
		i--;
	i++;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		j++;
	}
	return (j);
}

int					ft_txtend(char *str, int i)
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
		if (str[i] == 'd' || str[i] == 's' || str[i] == 'u' ||
			str[i] == 'p' || str[i] == 'x' || str[i] == 'X' ||
			str[i] == 'i' || str[i] == 'c')
		{
			while (str[i] != '%')
			{
				i++;
				if (str[i] == '\0')
					return (count);
				if (str[i] == '%')
					return (count);
				ft_putchar(str[i]);
				count++;
			}
			return (count);
		}
		i++;
	}
	return (count);
}

// int				ft_txtendpourc(char *str, int i)
// {
// 	int j;

// 	j = 0;
// 	while (str[i] != '%')
// 		i++;
// 	while (str[i])
// 	{
// 		j++;
// 		i++;
// 		if (str[i] == '%')
// 			return (j);
// 		if (str[i] == '\0')
// 			return (j);
// 		ft_putchar(str[i]);
// 	}
// 	return (j);
// }