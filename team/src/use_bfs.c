/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:16 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/16 18:57:19 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static t_visit	*init_visited(char **map)
{
	t_visit	*visit;
	int		i;
	int		j;

	i = 0;
	visit = (t_visit *)malloc(sizeof(t_visit));
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

	while (!is_empty(q))
	{
		pop = dequeue(q);
		if (pop->x - 1 >= 0)
			if (visit->visited[pop->y][pop->x - 1] == 0)
				visit_l(map, visit, q, pop);
		if (pop->x + 1 < ft_strlen2(map[pop->y]))
			if (visit->visited[pop->y][pop->x + 1] == 0)
				visit_r(map, visit, q, pop);
		if (pop->y - 1 >= 0)
			if (visit->visited[pop->y - 1][pop->x] == 0)
				visit_d(map, visit, q, pop);
		if (pop->y + 1 < ft_str_col(map))
			if (visit->visited[pop->y + 1][pop->x] == 0)
				visit_up(map, visit, q, pop);
		free(pop);
	}
}

int	bfs(char **map)
{
	t_visit	*visit;
	t_queue	*q;

	visit = init_visited(map);
	if (!visit)
		return (-1);
	q = init_queue();
	append_space_index(map, q);
	visit_four_direction(map, q, visit);
	if (visit->zero_cnt != 0)
		return (-1);
	return (1);
}
