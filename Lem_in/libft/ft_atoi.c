#include "libft.h"

static	int	ft_clear(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\f' && s[i + 1] == '-' && !ft_isdigit(s[i + 2]))
			return (1);
		else if (s[i] == '\e')
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(char *s)
{
	int sign;
	int num;

	sign = 1;
	num = 0;
	if (ft_clear(s))
		return (0);
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && ft_isdigit(*s))
	{
		num *= 10;
		num += (*s - '0');
		s++;
	}
	return (num * sign);
}
