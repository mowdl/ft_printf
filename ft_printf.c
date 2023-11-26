
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"


void	ft_putlong(long n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putlong_fd(-n, 1);
	}
	else if (n > 9)
	{
		ft_putlong_fd(n / 10, 1);
		ft_putlong_fd(n % 10, 1);
	}
	else
	{
		ft_putchar_fd('0' + n, 1);
	}
}

int	put_long(long n)
{
	int digits;

	ft_putnbr_fd(n, 1);
	if (n ==0)
		digits = 1;
	else
	{
		while (n != 0)
		{
			n /= 10;
			digits++;
		}
	}
	return (digits);
}

void	ft_put_unsigned_long_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlong_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putlong_fd(n / 10, fd);
		ft_putlong_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + n, fd);
	}
}

int	put_unsigned_long(unsigned long n)
{
	int digits;

	digits = 0;
	if (n == 0)
	{
		digits = 1;
	}
	else
	{
		while (n != 0)
		{
			ft_putchar_fd('0' + (n % 10),  1);
			n /= 10;
			digits++;
		}
	}
	return (digits);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int r;

	va_list ptr;
	va_start(ptr, str);

	r = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			r++;
		}
		else
		{
			if (str[i+1] == 'd' || str[i+1] == 'i')
			{
				r += put_long(va_arg(ptr, int));
				i++;
			}
			else if (str[i+1] == 'p' || str[i+1] == 'u')
			{
				r += put_unsigned_long(va_arg(ptr, int));
				i++;
			}
			else
			{			
				ft_putchar_fd(str[i], 1);
				r++;
			}
		}
		i++;
	}
	return (r);
}



