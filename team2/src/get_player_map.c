/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:22:42 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/19 16:23:46 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	player 위치를 받아오고, 상 하 검사하는데
	1. 위쪽 판별 케이스
		- 위로 전진하면서 해당 줄이 모두 space인가?
		- 위로 전진하면서 map[0]에 도달했는가?

	2. 아래쪽 판별 케이스
		- 아래로 전진하면서 해당 줄이 모두 space인가?
		- 아래로 전진하면서 해당 줄이 마지막 line인가?
*/


static int	is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	down_line(char **map, t_game *pos)
{
	// player 기준의 i(y값)을 받아오고 걔부터 돌아
	int	p_y;

	p_y = pos->info->p_pos[0];
	while (map[p_y])
	{
		if (is_all_space(map[p_y]) == 1) // 중간 섬이 playermap
			return (p_y - 1);
		p_y++;
	}
	return (p_y - 1); // 마지막 섬이 playermap
}

static int	up_line(char **map, t_game *pos)
{
	int	p_y;

	p_y = pos->info->p_pos[0];
	if (p_y == 0)
		return (p_y);
	while (map[p_y])
	{
		if (is_all_space(map[p_y]) == 1)
			return (p_y - 1);
		p_y--;
	}
	return (p_y - 1);
}

void	player_map(char **map, t_game *pos)
{
	char	**tmp;
	int		start;
	int		end;
	int		i;
	int		len;

	/*
		map의 몇번 째 줄인가? strdup를 몇번째 줄을 해야대? 얘 길이는 몇이야?
		start, end는 p_pos 기준 몇개의 줄을 올라가거나, 내려가거나를 반환한다.

		엥 그럼 start, end 둘 다 map의 idx 반환이 낫지않냐?????????
	*/
	i = 0;
	len = 0;
	start = 0;
	end = 0;
	// printf("%d %d\n", up_line(map, pos), down_line(map, pos));
	start = up_line(map, pos); // pos 기준 윗줄 시작점
	end = down_line(map, pos); // pos 기준 아랫줄 끝점
	tmp = (char **)malloc(sizeof(char *) * (end - start + 1));
	// !tmp
	printf("up : %d, down : %d\n", start, end);
	printf("player pos : %d\n", pos->info->p_pos[0]);
	while (start <= end)
	{
		len = ft_strlen(map[start]);
		tmp[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!tmp[i])
			ft_err("real map malloc err\n");
		tmp[i] = ft_strdup(map[start]);
		i++;
		start++;
	}
	tmp[end + 1] = NULL;
	ft_free(map);
	pos->info->map = tmp;
}
