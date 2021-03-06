/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isnum.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:38:57 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 11:58:17 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
