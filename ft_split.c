/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:31:49 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/07 13:01:35 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
    size_t s_len;
    size_t i=0;
    char *array;
    if(!s)
    {
      return NULL; 
    }
    s_len=ft_strlen(s);
    if(start >= s_len)
    {
        return (ft_strdup(""));
    }
    else if(len > s_len - start)
    {
        len=s_len - start;
    }
    array=(char *)(malloc(sizeof(char )*(len+1)));
    if(!array)
    {
        return NULL;
    }
    while (i < len && s[start + i] != '\0')
    {
        array[i]=s[start+i];
        i++;
    }
    array[i]='\0';
    return (array);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!array)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

void	free_matrix(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

 int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

 int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

 char	**free_split_failed(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		w_len;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			w_len = word_len(s, c);
			array[i] = ft_substr(s, 0, w_len);
			if (!array[i])
				return (free_split_failed(array, i));
			s += w_len;
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}