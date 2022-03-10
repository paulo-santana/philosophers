/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:13:54 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/09 21:31:51 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	will_overflow(int number, int digit)
{
	if (number > 0)
		return (number * 10 + digit < number);
	else
		return (number * 10 - digit > number);
}

int	is_int(char *number)
{
	int		i;
	int		is_negative;
	int		digit;
	long	as_int;

	i = 0;
	as_int = 0;
	is_negative = number[i] == '-';
	if (is_negative)
		i++;
	while (number[i])
	{
		digit = number[i] - '0';
		if (digit < 0 || digit > 9)
			return (0);
		if (will_overflow(as_int, digit))
			return (0);
		if (is_negative)
			as_int = as_int * 10 - digit;
		else
			as_int = as_int * 10 + digit;
		i++;
	}
	return (1);
}
