/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_initvar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:26:44 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:12:56 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			ft_initvar(Print *print, const char *str)
{
	print->ret = 0;
	print->neg = 0;
	print->typestring = NULL;
	print->typeint = 0;
	print->prec = 0;
	print->width = 0;
	print->width2 = 0;
	print->typechelou = 0;
	print->retpourc = 0;
	print->lint = 0;
	print->prec2 = 0;
	print->ret = ft_txt((char *)str);
}