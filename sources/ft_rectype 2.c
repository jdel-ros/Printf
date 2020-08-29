/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rectype.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:46:05 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 12:51:23 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_rectyperes(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 'i')
			return (1);
		if (str[i] == 'x' || str[i] == 'X')
			return (2);
		if (str[i] == 'u')
			return (3);
		if (str[i] == 's')
			return (4);
		if (str[i] == 'p')
			return (5);
		if (str[i] == 'c')
			return (6);
		if (ft_rectypepourc(str, i) == 1)
			return (7);
		i++;
	}
	return (0);
}

int				ft_rectypeint(Print *print, char *str, va_list ap, int i)
{
	int j;

	j = 0;
	if (print->typeres == 1 || print->typeres == 6)
		return (ft_type_cdi((char *)str, i, ap));
	return (0);
}

char			*ft_rectypestring(Print *print, char *str, va_list ap, int i)
{
	if (print->typeres == 3 || print->typeres == 4 || print->typeres == 5)
		ft_type_spu(print, (char *)str, i, ap);
	if (print->typeres == 2)
		ft_type_xx(print, (char *)str, i, ap);
	return (NULL);
}
