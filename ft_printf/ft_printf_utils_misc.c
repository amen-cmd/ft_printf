/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:07:32 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/07 16:05:18 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*myptr;

	i = 0;
	myptr = (char *)s;
	while (i++ < n)
		*(myptr++) = 0;
}

/* -------------------------------------------------------------------------- */

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *) ptr);
}

/* -------------------------------------------------------------------------- */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*output_str;
	size_t	output_i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	output_str = (char *) malloc((i + 1) * sizeof(char));
	if (!output_str)
		return (NULL);
	ft_bzero(output_str, (i + 1) * sizeof(char));
	if (!i)
		return (output_str);
	i = 0;
	output_i = 0;
	while (s1[i])
		output_str[output_i++] = s1[i++];
	i = 0;
	while (s2[i])
		output_str[output_i++] = s2[i++];
	return (output_str);
}

/* -------------------------------------------------------------------------- */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* -------------------------------------------------------------------------- */

void	ft_putnchar(char c, size_t n)
{
	while (n-- != 0)
		write(1, &c, 1);
}

/* -------------------------------------------------------------------------- */

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

/* -------------------------------------------------------------------------- */

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

/* -------------------------------------------------------------------------- */

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

/* -------------------------------------------------------------------------- */

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sum;
	char	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		sum = (sum * 10) + (str[i++] - '0');
	return (sum * sign);
}

/* -------------------------------------------------------------------------- */
