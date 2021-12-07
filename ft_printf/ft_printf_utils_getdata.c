/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_getdata.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:15:14 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 23:00:03 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	get_flags(char **field_ptr, t_flags *flags)
{
	char flag;

	while (**field_ptr && ft_isflag(**field_ptr))
	{
		flag = ft_isflag(**field_ptr);
		if (flag == '-')
			flags -> minus = 1;
		else if (flag == '+')
			flags -> plus = 1;
		else if (flag == ' ')
			flags -> space = 1;
		else if (flag == '0')
			flags -> zero = 1;
		else if (flag == '#')
			flags -> hash = 1;
		*field_ptr += 1;
	}
}

/* -------------------------------------------------------------------------- */

size_t get_width(char **field_ptr)
{
	size_t	the_width;

	the_width = 0;
	if (**field_ptr && ft_isdigit(**field_ptr))
		the_width = ft_atoi(*field_ptr);
	while (ft_isdigit(**field_ptr))
		*field_ptr += 1;
	return (the_width);
}

/* -------------------------------------------------------------------------- */

int get_precision(char **field_ptr)
{
	int	the_precision;

	the_precision = -1;
	if (**field_ptr == '.' && ft_isdigit(*(*field_ptr + 1)))
	{
		*field_ptr += 1;
		the_precision = ft_atoi(*field_ptr);
	}
	while (ft_isdigit(**field_ptr))
		*field_ptr += 1;
	return (the_precision);
}

/* -------------------------------------------------------------------------- */

char    get_type(char **field_ptr)
{
	if (**field_ptr && ft_istype(**field_ptr))
		return (ft_istype(**field_ptr));
	return (0);
}

/* -------------------------------------------------------------------------- */

void	get_data(t_fields *data, t_flags *flags, char *field_ptr, size_t *index)
{
	char		*initial_ptr;

	initial_ptr = field_ptr;
	data -> flags = flags;
	get_flags(&field_ptr, flags);
	data -> width = get_width(&field_ptr);
	data -> precision = get_precision(&field_ptr);
	data -> type = get_type(&field_ptr);
	*index += field_ptr - initial_ptr;
}

/* -------------------------------------------------------------------------- */
