/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:34:27 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:42:40 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int			ft_ifetoilewidth(char *str, int i)
{
	while (str[i] != '%')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i' ||
			str[i] == 's' || str[i] == 'p' || str[i] == 'x' ||
			str[i] == 'X' || str[i] == 'u')
			return (0);
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_widthlen(char *str, int i)
{
	int			len;

	len = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (len);
		if (str[i] == 'd' || str[i] == 's' || str[i] == 'u' ||
		str[i] == 'p' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == 'i' || str[i] == 'c')
			return (len);
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			len++;
		}
		else
			i++;
	}
	return (len);
}

void			ft_width(char *str, Print *print, va_list ap, int i)
{
	char		*widthstring2;
	char		*s;
	int			j;
	int			len;

	j = 0;
	if (ft_ifwidth(str, i) == 0)
	{
		print->width = 0;
		return ;
	}
	len = ft_widthlen(str, i);
	if (ft_ifetoilewidth(str, i) == 1)
	{
		print->width = va_arg(ap, int);
		return ;
	}
	if (len != 0)
	{
		if (!(widthstring2 = (char *)malloc(sizeof(char) * (len + 1))))
			return ;
		widthstring2[len] = '\0';
		s = ft_strdup(str);
		while (s[i])
		{
			if (str[i] == '.')
			{
				print->width = ft_atoi_printf(widthstring2);
				free(s);
				free(widthstring2);
				return ;
			}
			if (s[i] == 'd' || s[i] == 's' || s[i] == 'u' ||
			s[i] == 'p' || s[i] == 'x' || s[i] == 'X' ||
			s[i] == 'i' || s[i] == 'c')
			{
				print->width = ft_atoi_printf(widthstring2);
				free(s);
				free(widthstring2);
				return ;
			}
			if (s[i] >= 48 && s[i] <= 57)
				widthstring2[j++] = s[i++];
			else
				i++;
		}
	}
}
