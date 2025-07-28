/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:43:40 by ipavlov           #+#    #+#             */
/*   Updated: 2024/11/09 11:48:32 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_store_place(int fd, char *store_place);

int		ft_strlen(const char *s);
void	*ft_calloc(int nmemb, int size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr_t_f(const char *s, int c);
void	ft_free(char **ptr);

#endif