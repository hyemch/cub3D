/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:16 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 16:53:09 by suhwpark         ###   ########.fr       */
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

static void	visit_four_direction(char **map, t_queue *q, t_visit *visit, int c)
{
	t_node	*pop;
	int		row;

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
		if (pop->y - 1 >= 0 && pop->x <= (int)ft_strlen(map[pop->y - 1]))
			if (visit->visited[pop->y - 1][pop->x] == 0)
				visit_up(map, visit, q, pop);
		if (pop->y + 1 < c && pop->x <= (int)ft_strlen(map[pop->y + 1]))
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
		return (FALSE);
	q = init_queue();
	append_space_index(map, q);
	visit_four_direction(map, q, visit, ft_str_col(map));
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
