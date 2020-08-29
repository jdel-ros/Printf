/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:34:27 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:30:59 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int		ft_widthlen(char *str, int i)
{
	int			len;

	len = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (len);
		if (ft_chr_type(str, i) == 0)
			return (len);
		if (str[i] >= 48 && str[i] <= 57)
			len++;
		i++;
	}
	return (len);
}

static	void	ft_recwd(char *str, t_print *print, int i, char *widthstring2)
{
	print->len = ft_widthlen(str, i);
	if (!(widthstring2 = (char *)malloc(sizeof(char) * (print->len + 1))))
		return ;
	widthstring2[print->len] = '\0';
	i++;
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 's' || str[i] == 'u' || str[i] == 'p' ||
			str[i] == 'x' || str[i] == 'X' || str[i] == 'i' || str[i] == 'c' ||
			str[i] == '%' || str[i] == '.')
		{
			print->width = ft_atoi_printf(widthstring2);
			free(widthstring2);
			return ;
		}
		if (str[i] >= 48 && str[i] <= 57)
			widthstring2[print->j++] = str[i++];
		else
			i++;
	}
	free(widthstring2);
}

void			ft_width(char *str, t_print *print, va_list ap, int i)
{
	char		*widthstring2;

	widthstring2 = NULL;
	print->j = 0;
	if (ft_ifwidth(str, i) == 0)
	{
		print->width = 0;
		return ;
	}
	print->len = ft_widthlen(str, i);
	if (ft_ifwidthetoile(str, i) == 1)
	{
		print->width = va_arg(ap, int);
		return ;
	}
	if (print->len != 0)
		ft_recwd(str, print, i, widthstring2);
}
