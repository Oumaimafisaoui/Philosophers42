#include "header.h"

int	ft_is_digit(char *s)
{
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}
size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while(str[index] != '\0')
		index++;
	return (index);
}

int ft_atoi(const char *dest)
{
	int	sign;
	int 	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;

	if(*dest == 0)
		return (0);

	while (dest[i] ==  ' ' || (dest[i] >= 9 && dest[i] <= 13))
		i++;

	if(dest[i] == '+' || dest[i] == '-')
	{
		if(dest[i] == '-')
			sign *= -1;
		i++;
	}

	while(dest[i] && dest[i] <= '9' && dest[i] >= '0')
	{
		result *= 10;
		result += (dest[i] - 48);
		i++;
	}
	return (result * sign);
}


void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
 