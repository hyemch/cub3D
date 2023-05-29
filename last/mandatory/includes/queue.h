/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:48:48 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:47 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_visit
{
	int	**visited;
	int	zero_cnt;
}	t_visit;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
}	t_queue;

t_queue	*init_queue(void);
t_node	*enqueue(t_queue *queue, int x, int y);
t_node	*dequeue(t_queue *queue);

int		is_empty(t_queue *queue);
void	clear_queue(t_queue *queue);
void	*safe_malloc(size_t	size);
void	visit_l(char **map, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	visit_r(char **map, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	visit_d(char **map, t_visit *visit_info,
			t_queue *queue, t_node *point);			
void	visit_up(char **map, t_visit *visit_info,
			t_queue *queue, t_node *point);
void	free_t_visit(t_visit *visit_info);
#endif