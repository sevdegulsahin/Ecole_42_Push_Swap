/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:31:49 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 19:34:14 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}


char **free_all(char **s, int i)
{
    while (i--)
        free(s[i]);
    free(s);
    return (NULL);
}

int  word_count(const char *s, char c)
{
    int count;

    count = 0;
    while (*s)
    {
        if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
            count++;
        s++;
    }
    return (count);
}

int  word_len(const char *s, char c)
{
    int len;

    len = 0;
    while (s[len] != c && s[len] != '\0')
        len++;
    return (len);
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    int     i;
    if (!s)
        return (NULL);
    i = 0;
    array = malloc(sizeof(char *) * (word_count(s, c) + 1));
    if (!array)
        return (NULL);
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
        {
            array[i] = ft_substr(s, 0, word_len(s, c));
            if (!array[i])
                return (free_all(array, i));
            i++;
            s = s + word_len(s, c);
        }
    }
    array[i] = NULL;
    return (array);
}