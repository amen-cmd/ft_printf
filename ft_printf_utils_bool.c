
#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

int	is_width(char c)
{
	return (c >= '1' && c <= '9');
}

/* -------------------------------------------------------------------------- */

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
        return (c);
    return (0);
}

/* -------------------------------------------------------------------------- */

int	is_precision(char *s)
{
    if (*s == '.' && is_width(*(s + 1)))
        return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */