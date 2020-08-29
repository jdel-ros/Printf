/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exectype.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 19:15:55 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:26:12 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_exectype(char *str, t_print *print, int i)
{
	if (print->typeres == 1)
		ft_execint(str, print, i);
	else if (print->typeres == 2 || print->typeres == 3)
		ft_exec_u_x(str, print, i);
	else if (print->typeres == 4)
		ft_exec_string(print, str, i);
	else if (print->typeres == 5)
		ft_execpointer(print, str, i);
	else if (print->typeres == 6)
		ft_execchar(print);
	else if (print->typeres == 7)
		ft_execpourc(print);
	return (print->ret);
}
