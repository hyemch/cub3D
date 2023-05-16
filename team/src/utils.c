/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:17:38 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/16 13:58:32 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	*safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_putendl_fd("malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

int	ft_size(char **str) // 2차원 사이즈 카운트 함수
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (str[++i])
	{
		if (str[i])
			size++;
	}
	return (size);
}

void	ft_err(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}
