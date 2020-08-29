/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_front_bonus.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 16:06:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 12:08:13 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!(new || alst))
		return ;
	new->next = *alst;
	*alst = new;
}
