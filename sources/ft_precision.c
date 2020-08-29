/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:04:39 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:30:42 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int		ft_preclen(char *str, int i)
{
	int				len;

	len = 0;
	while (str[++i] != '.')
	{
		if (str[i] == '\0')
			return (len);
		if (ft_chr_type(str, i) == 0)
			return (len);
	}
	while (str[i])
	{
		if (ft_chr_type(str, i) == 0)
			return (len);
		if (str[i] >= 48 && str[i] <= 57)
			len++;
		i++;
	}
	return (len);
}

static	void	ft_recpc(char *str, t_print *print, int i, char *precstring2)
{
	print->len = ft_preclen(str, i);
	if (!(precstring2 = (char *)malloc(sizeof(char) * (print->len + 1))))
		return ;
	precstring2[print->len] = '\0';
	while (str[i] != '.')
		i++;
	while (str[i])
	{
		if (ft_chr_type(str, i) == 0)
		{
			print->prec = ft_atoi_printf(precstring2);
			free(precstring2);
			return ;
		}
		if (str[i] >= 48 && str[i] <= 57)
			precstring2[print->j++] = str[i++];
		else
			i++;
	}
	free(precstring2);
}

void			ft_precision(char *str, t_print *print, va_list ap, int i)
{
	char		*precstring2;

	print->j = 0;
	precstring2 = NULL;
	print->len = ft_preclen(str, i);
	if (ft_ifprecetoile(str, i) == 1)
	{
		print->prec = va_arg(ap, int);
		if (print->prec < 0)
		{
			print->prec2 = print->prec;
			print->prec = 0;
		}
		return ;
	}
	if (print->len != 0)
		ft_recpc(str, print, i, precstring2);
}
