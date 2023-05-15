/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:35:04 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 18:03:06 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
// 여기서 맵 context에 대한 검수를 하면 될거같아요
/*
맵 파싱
2. 벽에 다 둘러 싸이게
2. cub 파일의 마지막에 위치하도록 -> 맵 마지막줄 뒤에 EOF 검수?
3. 제시된 콘텐츠 외에 다른게 들어오면 안됨
4. 제시된 콘텐츠가 부족해도 안됨 벽과 벽을 제외한 콘텐츠에서 공백 안됨
5. 직사각형이 아닌 맵 1 검수 -> whitespace가 아닌 문자를 처음 만났을 때 1, 개행 전에 1인지?
*/

int	ft_str_col(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	return (i);
}


int	start_end_wall(char *map)
{
	//1 아니면 스페이스바 외에 다른게 들어오면 안됨 추가적으로 len 맞춰바야댐?
	int	i;

	i = is_whitespace(map);
	while (map[i++])
		if (map[i] != '1' && map[i] != ' ')
			return(-1);
	return (1);
}

int	check_wall(char *map, int len)
{
	int	i;
	
	i = is_whitespace(map);
	if (map[i] != 1 || map[len - 1] != 1) // 양 끝부분 1로 돼있음?
		return (-1);
	return(1);
}

// 추가적으로 맵 중간에 빈줄이 있으면 안되게 -> 얘는 gnl 총 라인 개수랑 
// validation 후의 개수를 비교해야될거같은데 어덕?????
// gnl을 변형시켜야되나여

int	all_around_wall(char **map) // 이차원이라 생각할게여
{
	int i;
	int	len;

	i = 0;
	len = ft_str_col(map);	
	while (map[i])
	{
		if (i == 0 || i == len)
		{
			if (start_end_wall(map[i]) == -1);
			{
				ft_free(map);
				return (-1);
			}
		}
		else
		{
			if (check_wall(map[i], ft_strlen(map[i])) == -1);
			{
				ft_free(map);
				return (-1);
			}
		}
	}
	return (1);
}

int	context_check(char context, t_game *dir) // WASD중 하나 있는지 봐야되는디요
{
	if (context != '0' && context != '1' && context != 'W' \
		&& context != 'S' && context != 'A' && context != 'D')
			return (-1);
	if (context == 'W')
		dir->w++;
	else if (context == 'A')
		dir->a++;
	else if (context == 'S')
		dir->s++;
	else if (context == 'D')
		dir->d++;
	if (dir->w >= 2 || dir->a >= 2 || dir->s >= 2 || dir->d >= 2)
	{
		ft_err("player count err\n");
		return (-1);
	}
	return (1);
}

int	space_check(char **map, t_game *dir) //WASD, 1, 0만 있어야댐
{
	int	i;
	int	j;
	int	col;

	col = ft_str_col(map);
	i = 1;
	while (map[i] && i < col)
	{
		j = 0;
		while (map[i][j])
		{
			if (context_check(map[i][j], dir) == -1)
			{
				ft_free(map);
				return (-1);
			}
			if (map[i][j] == ' ')
				bfs_test(map, i, j);
		}
		i++;
	}
	if (dir->w == 0 && dir->a == 0 && dir->s == 0 && dir->d == 0)
	{
		ft_free(map);
		ft_err("player count err\n");
		return (-1);
	}
	return (1);
}

int	bfs_test(t_visit *visit, char **map, int i, int j)
{
	int	**visited;
	int	i;
	int	j;
	t_visit	*visit;
	
	i = 0;
	visit = (t_visit *)malloc(sizeof(t_visit));
	visited = (int **)malloc(sizeof(int *) * (ft_str_col(map) + 1));
	if (!visited)
		return (-1);
	while (map[i])
	{
		j = ft_strlen(map[i]);
		visited[i] = (int *)malloc(sizeof(int) * j);
		if (!visited[i])
			return (-1);
		ft_memset(visited[i], 0, j);
		i++;
	}
	visited[i] = NULL;
	visit->visited = visited;
	visit->cnt = 0;
}