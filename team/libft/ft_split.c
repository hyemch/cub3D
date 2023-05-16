/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:19:10 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 21:06:25 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	arr_size(const char *s)
// {
// 	size_t	num;

// 	num = 0;
// 	while (*s)
// 	{
// 		if (!ft_isspace(*s))
// 		{
// 			while (*s && !ft_isspace(*s))
// 				s++;
// 			num++;
// 		}
// 		else
// 			s++;
// 	}
// 	return (num);
// }

// static size_t	alloc_size(char const *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] && !ft_isspace(s[i]))
// 		i++;
// 	return (i);
// }

// static void	*free_answer(char **answer, size_t index)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < index)
// 	{
// 		free(answer[i]);
// 		i++;
// 	}
// 	free(answer);
// 	return (NULL);
// }

// char	**ft_split(char const *s)
// {
// 	char	**answer;
// 	size_t	arr_cnt;
// 	size_t	alloc_cnt;
// 	size_t	index;

// 	index = 0;
// 	arr_cnt = arr_size(s);
// 	answer = (char **)malloc(sizeof(char *) * (arr_cnt + 1));
// 	if (!answer)
// 		return (NULL);
// 	while (arr_cnt--)
// 	{
// 		while (*s && ft_isspace(*s))
// 			s++;
// 		alloc_cnt = alloc_size(s) + 1;
// 		answer[index] = (char *)malloc(alloc_cnt);
// 		if (!answer[index])
// 			return (free_answer(answer, index));
// 		ft_strlcpy(answer[index++], s, alloc_cnt);
// 		s = ft_strchr(s, );
// 	}
// 	answer[index] = NULL;
// 	return (answer);
// }
static int	is_word(char word, char c)
{
	if (word == c)
		return (0);
	else
		return (1);
}

static size_t	get_size(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (is_word(*s, c))
		{
			count++;
			while (*s && is_word(*s, c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**all_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	const char	*tmp;
	size_t		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (get_size(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		if (is_word(*s, c))
		{
			tmp = s;
			while (*s && is_word(*s, c))
				s++;
			res[i] = (char *)malloc(sizeof(char) * (s - tmp + 1));
			if (!res[i])
				return (all_free(res));
			ft_strlcpy(res[i++], tmp, (s - tmp + 1));
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

// int main(int ac, char *av[])
// {
// 	char **s;
// 	int i = 0;
	
// 	s = ft_split(av[1]);
// 	if (!s[i])
// 	{
// 		printf("a");
// 	}
// 	else
// 		printf("b");
// 	while (s[i])
// 	{
// 		printf("%s", s[i]);
// 		printf("||");
// 		printf("\n");
// 		i++;
// 	}
// 	return (0);
// }
