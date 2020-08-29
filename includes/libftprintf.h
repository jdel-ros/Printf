/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:12:15 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:24:45 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_print
{
	char		flags;
	char		*widthstring;
	char		*precstring;
	int			width;
	int			prec;
	int			typeint;
	char		*typestring;
	int			typeres;
	int			neg;
	int			typechelou;
	int			ret;
	int			retpourc;
	long int	lint;
	int			width2;
	int			prec2;
	int			txtend;
	int			j;
	int			len;
	int			moins;
}				t_print;

int				ft_atoi_printf(char *nptr);
int				ft_chrprecstring(char *str, int i);
int				ft_chr_type(char *str, int i);
int				ft_execchar(t_print *print);
int				ft_execint(char *str, t_print *print, int i);
int				ft_execintneg(t_print *print);
int				ft_execintneg_two(t_print *print);
int				ft_execwidth(t_print *print, char *str, int i);
int				ft_execwidthfz(t_print *print, char *str, int i);
int				ft_execwidthneg(t_print *print, char *str, int i);
int				ft_execwidthff(t_print *print, char *str, int i);
int				ft_execwidthfm(t_print *print, char *str, int i);
int				ft_execprec(t_print *print);
int				ft_execpourc(t_print *print);
int				ft_weird(char *str, int i, t_print *print);
int				ft_weird_two(char *str, int i, t_print *print);
int				ft_execpointer(t_print *print, char *str, int i);
int				ft_exec_string(t_print *print, char *str, int i);
int				ft_exec_u_x(char *str, t_print *print, int j);
int				ft_exectype(char *str, t_print *print, int i);
void			ft_flags(char *str, t_print *print, int i);
int				ft_ifwidth(char *str, int i);
int				ft_ifwidthetoile(char *str, int i);
int				ft_ifwidth_flagsz(char *str, int i);
int				ft_ifprecetoile(char *str, int i);
int				ft_intlenbase(long int n, char *base);
int				ft_intprecinf(t_print *print);
int				ft_intprecspe(t_print *print);
int				ft_intlen(long int i);
int				ft_intchr(const char *s, int c, int i);
void			ft_initvar(t_print *print, const char *str);
void			ft_precision(char *str, t_print *print, va_list ap, int i);
int				ft_printf(const char *str,
						...) __attribute__((format(printf,1,2)));
int				ft_rectypepourc(char *str, int i);
int				ft_rectyperes(char *str, int i);
void			ft_rectype(t_print *print, char *str, va_list ap, int i);
int				ft_txt(char *str);
int				ft_txtend(t_print *print, char *str, int i);
int				ft_txtendpourc(t_print *print, char *str, int i);
void			ft_type_sp(t_print *print, char *str, int i, va_list ap);
void			ft_type_xxu(t_print *print, char *str, int i, va_list ap);
void			ft_type_cdi(t_print *print, char *str, int i, va_list ap);
int				ft_unsignedlenbase(unsigned long n, char *base);
void			ft_width_prec_neg(char *str, t_print *print, int i);
void			ft_width(char *str, t_print *print, va_list ap, int i);
#endif
