/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rectypourc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 14:08:17 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 10:43:45 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_rectypepourc(char *str, int i)
{
	int j;

	j = 0;
	if (str[i] == '%')
	{
		while (j != i)	
			j++;
		j++;
		while (str[j] != '%')
		{
			if (str[j] == '\0')
				return (0);
			j++;
		}
		i--;
		while (i < j)
		{
			i++;
			if (str[i] == '0' || str[i] == '-')
				i++;
			else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
				i++;
			else if (str[i] == '.')
				i++;
			else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
				i++;
			if (str[i] == 's' || str[i] == 'p' || str[i] == 'u' ||
				str[i] == 'x' || str[i] == 'X' || str[i] == 'd' ||
				str[i] == 'i' || str[i] == 'c')
				return (0);
		}
		if (i == j)
			return (1);
	}
	return (0);
}