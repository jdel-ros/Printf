/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 10:20:21 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 10:30:24 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_intchr(const char *s, int c, int i)
{
	int len;

	len = ft_strlen(s);
	if (!(s))
		return (0);
	if (c == '\0')
		return (len);
	while (s[i] && s[i] != c)
		i++;
	if (i == len)
		return (len);
	else
		return (i);
}

// int			main(void)
// {
// 	int i;
// 	const char *s = "ft_printf(line :|%*d|str :|%s|, -45, 10, bonjour)";

// 	i = 0;
// 	while (i < (int)ft_strlen((char *)s))
// 	{
// 		i = ft_intchr(s, '%', i);
// 		i++;
// 		printf("|%d|", i);
// 	}
// }