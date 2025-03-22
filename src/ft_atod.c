/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:36:59 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 14:59:52 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	parse_sign_and_integer(const char **str, int *sign)
{
	double	value;

	value = 0.0;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	while (**str && **str != '.')
	{
		if (**str <= '9' && **str >= '0')
		{
			value = value * 10.0 + (**str - '0');
			(*str)++;
		}
		else
			break ;
	}
	return (value);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	value;
	double	decimal_multiplier;

	sign = 1;
	value = parse_sign_and_integer(&str, &sign);
	decimal_multiplier = 0.1;
	if (*str == '.')
	{
		str++;
		while (*str && *str <= '9' && *str >= '0')
		{
			value += (*str - '0') * decimal_multiplier;
			decimal_multiplier *= 0.1;
			str++;
		}
	}
	return (value * sign);
}
