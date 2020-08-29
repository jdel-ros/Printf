/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rectype.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:46:05 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 14:45:31 by jdel-ros    ###    #+. /#+    ###.fr     */
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

void			ft_rectype(t_print *print, char *str, va_list ap, int i)
{
	if (print->typeres == 1 || print->typeres == 6)
		return (ft_type_cdi(print, str, i, ap));
	if (print->typeres == 2 || print->typeres == 3)
		ft_type_xxu(print, str, i, ap);
	if (print->typeres == 4 || print->typeres == 5)
		ft_type_sp(print, str, i, ap);
}
