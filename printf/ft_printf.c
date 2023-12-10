/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:48:41 by luqli             #+#    #+#             */
/*   Updated: 2023/11/27 14:48:42 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_check(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (format == 'u')
		len += ft_putun(va_arg(args, unsigned int));
	if (format == 'x')
		len += ft_puthex_low(va_arg(args, unsigned int));
	if (format == 'X')
		len += ft_puthex_up(va_arg(args, unsigned int));
	if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format_check(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>
int	main()
{
	int val = 42;
	int *ptr = &val;
	int i = printf("%p\n", ptr);
	int j = ft_printf("%p\n", ptr);
	printf("return value of original printf: ");
	printf("%i\n", i);
	printf("return value of ft_printf: ");
	printf("%i\n", j);
}*/