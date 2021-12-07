/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_processdata.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:18:00 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:37:19 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	process_data(t_fields *data, va_list *ap, size_t *outpt_len)
{
	if (data -> type == 'c')
		process_char(data, va_arg(*ap, int), outpt_len);
	else if (data -> type == 's')
		process_str(data, va_arg(*ap, char *), outpt_len);
	/*else if (data -> type == 'p')
		*outpt_len += process_vptr(data, va_arg(*ap, unsigned long));
	else if (data -> type == 'd' || data -> type == 'i')
		*outpt_len += process_sint(data, va_arg(*ap, signed int));
	else if (data -> type == 'u')
		*outpt_len += process_uint(data, va_arg(*ap, unsigned int));
	else if (data -> type == 'x' || data -> type == 'X')
		*outpt_len += process_hex(data, va_arg(*ap, unsigned int));*/
}

/* -------------------------------------------------------------------------- */

void	process_char(t_fields *data, char c, size_t *outpt_len)
{
	data -> flags -> plus = 0;
	data -> flags -> zero = 0;
	data -> flags -> space = 0;
	data -> flags -> hash = 0;
	data -> precision = 0;
	if (data -> flags -> minus)
	{
		ft_putchar(c, outpt_len);
		if (data -> width)
			ft_putnchar(' ', (data -> width) - 1, outpt_len);
	}
	else
	{
		if (data -> width)
			ft_putnchar(' ', (data -> width) - 1, outpt_len);
		ft_putchar(c, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_str(t_fields *data, char *str, size_t *outpt_len)
{
	size_t	str_len;

	data -> flags -> plus = 0;
	data -> flags -> zero = 0;
	data -> flags -> space = 0;
	data -> flags -> hash = 0;
	str_len = ft_strlen(str);
	if (data -> precision >= 0 && data -> precision < (int)str_len )
		str_len = (size_t) data -> precision;
	if (data -> width > str_len)
		data -> width = (data -> width) - str_len;
	if (data -> flags -> minus)
	{
		ft_putstr_len(str, str_len, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putstr_len(str, str_len, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */
