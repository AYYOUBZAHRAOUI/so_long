/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:45:08 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/20 17:02:25 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
int		fndnln(char *str, int n);
char	*fg_substr(char *s, unsigned int start, size_t len);
char	*fg_strdup(char *s1);
size_t	fg_strlen(const char *s);
char	*fg_strjoin(char *s1, char *s2);
void	*fg_memcpy(void *dst, const void *src, size_t len);

#endif