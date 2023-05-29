/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:19:10 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:27 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	size_t	i;
	size_t	wordlen;

	i = 0;
	wordlen = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		wordlen++;
	}
	return (wordlen);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (n + 1));
	if (!word)
		return (0);
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **list, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wordlen;
	size_t	count;
	char	**word;

	i = 0;
	count = word_count(s, c);
	word = (char **)malloc(sizeof(char *) * (count + 1));
	if (!word)
		return (0);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		wordlen = word_len(s, c);
		word[i] = ft_strndup(s, wordlen);
		if (!word[i])
			return (ft_free(word, i));
		s += wordlen;
		i++;
	}
	word[count] = 0;
	return (word);
}
