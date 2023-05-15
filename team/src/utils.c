/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:17:38 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 17:24:30 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
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
