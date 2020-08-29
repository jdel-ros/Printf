/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:57:28 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 13:09:18 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void				ft_flags(char *str, Print *print, int i)
{
	while (str[i] != '%')
		i++;
	i++;
	if (str[i] == '-')
		print->flags = '-';
	else if (str[i] == '0')
	{
		if (str[i + 1] == '-')
			print->flags = '-';
		else
			print->flags = '0';
	}
	else
		print->flags = 49;
}
