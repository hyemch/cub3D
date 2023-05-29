/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:45:22 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:34 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_rear;

	str_rear = (char *)str + ft_strlen(str);
	while (str <= str_rear)
	{
		if (*str_rear == (char)c)
			return (str_rear);
		str_rear--;
	}
	return (NULL);
}
