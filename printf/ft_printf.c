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
		len += ft_putptr(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (format == 'u')
		len += ft_putun(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, int));
	if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);// access the list of variable parameters
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format_check(format[i + 1], args);
			i++;// skip the second letter of the format
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main()
{
    char *ptr = "ha";
    int a = printf("%p", ptr);
    printf("\n");
    printf("%i", a);
	// return the length of the address of the pointer
}
*/
