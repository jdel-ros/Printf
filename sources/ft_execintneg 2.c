/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execintneg.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 13:05:09 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 08:49:51 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_execintneg(Print *print)
{
	if (print->lint < 0)
		if (print->flags == '1' || print->flags == '0' || print->flags == '-')
		{
			print->lint = print->lint * -1;
			return (1);
		}
	return (0);
}
