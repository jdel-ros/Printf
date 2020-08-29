/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_toupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:18:20 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/03 12:06:27 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = (c - 32);
			return (c);
		}
		else
			return (c);
	}
	return (0);
}
