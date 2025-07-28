/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:43:47 by ipavlov           #+#    #+#             */
/*   Updated: 2024/11/05 14:21:05 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(int nmemb, int size)
{
	int				total;
	int				i;
	void			*ptr;
	unsigned char	*s;

	total = nmemb * size;
	if (nmemb > 0 && size > 0)
	{
		if (!(total % nmemb == 0) || !(total % size == 0))
			return (NULL);
	}
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	s = (unsigned char *)ptr;
	while (i < total)
	{
		s[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_cat;
	int		size_all;
	int		i;
	int		j;

	size_all = ft_strlen(s1) + ft_strlen(s2);
	str_cat = (char *)malloc((size_all + 1) * sizeof(char));
	if (str_cat == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str_cat[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str_cat[j++] = s2[i++];
	str_cat[j] = '\0';
	return (str_cat);
}

int	ft_strchr_t_f(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
