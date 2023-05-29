/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:58:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:46 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

t_queue	*init_queue(void)
{
	t_queue	*ret;

	ret = (t_queue *)safe_malloc(sizeof(t_queue));
	ret->front = (t_node *)safe_malloc(sizeof(t_node));
	ret->front->next = NULL;
	ret->rear = ret->front;
	return (ret);
}

t_node	*enqueue(t_queue *queue, int x, int y)
{
	t_node	*new;

	new = (t_node *)safe_malloc(sizeof(t_node));
	new->x = x;
	new->y = y;
	new->next = NULL;
	queue->rear->next = new;
	queue->rear = new;
	return (new);
}

t_node	*dequeue(t_queue *queue)
{
	t_node	*ret;

	ret = queue->front->next;
	if (ret)
		queue->front->next = ret->next;
	if (queue->rear == ret)
		queue->rear = queue->front;
	return (ret);
}

int	is_empty(t_queue *queue)
{
	if (!queue->front->next)
		return (1);
	return (0);
}

void	clear_queue(t_queue *queue)
{
	while (!is_empty(queue))
		free(dequeue(queue));
	free(queue->front);
	free(queue);
}
