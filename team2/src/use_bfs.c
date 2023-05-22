/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:16 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/22 14:49:10 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static t_visit	*init_visited(char **map)
{
	t_visit	*visit;
	int		i;
	int		j;

	i = 0;
	visit = (t_visit *)safe_malloc(sizeof(t_visit));
	visit->visited = (int **)safe_malloc(sizeof(int *) * (ft_str_col(map) + 1));
	while (map[i])
	{
		j = ft_strlen(map[i]);
		visit->visited[i] = (int *)ft_calloc(sizeof(int), j);
		if (!visit->visited[i])
			return (NULL);
		i++;
	}
	visit->visited[i] = NULL;
	visit->zero_cnt = 0;
	return (visit);
}

void	append_space_index(char **map, t_queue *q)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				enqueue(q, j, i);
			j++;
		}
		i++;
	}
}

void	visit_four_direction(char **map, t_queue *q, t_visit *visit)
{
	t_node	*pop;
	int		col;
	int		row;

	row = 0;
	col = ft_str_col(map);
	while (!is_empty(q))
	{
		pop = dequeue(q);
		row = ft_strlen(map[pop->y]);
		if (pop->x - 1 >= 0)
			if (visit->visited[pop->y][pop->x - 1] == 0)
				visit_l(map, visit, q, pop);
		if (pop->x + 1 < row)
		{
			if (visit->visited[pop->y][pop->x + 1] == 0)
				visit_r(map, visit, q, pop);
		}
		if (pop->y - 1 >= 0 && pop->y - 1 < (int)ft_strlen(map[pop->y]))
			if (visit->visited[pop->y - 1][pop->x] == 0)
				visit_up(map, visit, q, pop);
		if (pop->y + 1 < col && pop->y + 1 > (int)ft_strlen(map[pop->y]))
			if (visit->visited[pop->y + 1][pop->x] == 0)
				visit_d(map, visit, q, pop);
		free(pop);
	}
}

int	bfs(char **map)
{
	t_visit	*visit;
	t_queue	*q;
	int		i;

	i = 0;
	visit = init_visited(map);
	if (!visit)
		return (-1);
	q = init_queue();
	append_space_index(map, q);
	visit_four_direction(map, q, visit);
	clear_queue(q);
	if (visit->zero_cnt != 0)
	{
		while (visit->visited[i])
			free(visit->visited[i++]);
		free(visit->visited);
		free(visit);
		return (FALSE);
	}
	while (visit->visited[i])
		free(visit->visited[i++]);
	free(visit->visited);
	free(visit);
	return (TRUE);
}
