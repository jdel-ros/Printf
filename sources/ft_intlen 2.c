/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 15:19:08 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 16:35:20 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_intlen(long int i)
{
	int				res;
	long long int	a;

	res = 0;
	a = (long long int)i;
	if (a < 0)
	{
		a = a * -1;
		res++;
	}
	while (a > 9)
	{
		a = a / 10;
		res++;
	}
	return (res + 1);
}
