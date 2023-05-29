/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:42:48 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:56 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_INT -2147483648

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if ((res & MIN_INT) != 0)
			return (-1);
	}
	if (!i && !str[i])
		return (-1);
	if (!('0' <= str[i] && str[i] <= '9') && str[i])
		return (-1);
	return (res);
}

// int	ft_atoi(char *str)
// {
// 	int		sign;
// 	long	result;

// 	sign = 1;
// 	result = 0;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign *= -1;
// 		str++;
// 	}
// 	while (*str && *str >= '0' && *str <= '9')
// 	{
// 		result = result * 10 + (*str - '0');
// 		if ((result & MIN_INT) != 0)
// 			return (-1);
// 		str++;
// 	}
// 	return (result * sign);
// }
