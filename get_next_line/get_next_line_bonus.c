/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:45:37 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/20 17:03:13 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fg_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = fg_strlen(s);
	if (start >= i)
		return (NULL);
	if (start + len > i)
		return (fg_strdup((s + start)));
	else
	{
		p = (char *)malloc(len + 1);
		if (p == NULL)
			return (NULL);
		p = fg_memcpy(p, (s + start), len);
		p[len] = '\0';
		return (p);
	}
}

char	*read_by_buffer(int fd, char *stt_str)
{
	int		rd_size;
	char	*bufstr;
	char	*read_box;

	read_box = NULL;
	if (!stt_str || (fndnln(stt_str, fg_strlen(stt_str)) < 0))
	{
		bufstr = (char *)malloc(BUFFER_SIZE + 1);
		if (!bufstr)
			return (NULL);
		rd_size = read(fd, bufstr, BUFFER_SIZE);
		while (rd_size > 0)
		{
			bufstr[rd_size] = '\0';
			if (!((fndnln(bufstr, rd_size)) >= 0))
				read_box = fg_strjoin(read_box, fg_substr(bufstr, 0, rd_size));
			else
				return (fg_strjoin(stt_str, fg_strjoin(read_box, bufstr)));
			rd_size = read(fd, bufstr, BUFFER_SIZE);
		}
		if (rd_size == -1)
			return (free(bufstr), free(stt_str), free(read_box), NULL);
		return (free(bufstr), fg_strjoin(stt_str, read_box));
	}
	return (stt_str);
}

char	*find_line(char *stt_str)
{
	int	new_line_idx;

	new_line_idx = fndnln(stt_str, fg_strlen(stt_str));
	if (new_line_idx >= 0)
		return (fg_substr(stt_str, 0, new_line_idx + 1));
	else
		return (fg_substr(stt_str, 0, fg_strlen(stt_str)));
}

char	*save_thing(char *stt_str)
{
	int		new_line_idx;
	char	*box;

	new_line_idx = fndnln(stt_str, fg_strlen(stt_str));
	if (new_line_idx >= 0)
	{
		box = fg_substr(stt_str, new_line_idx + 1, (fg_strlen(stt_str)
					- (new_line_idx + 1)));
		return (free(stt_str), stt_str = NULL, box);
	}
	else
		return (free(stt_str), stt_str = NULL, NULL);
}

char	*get_next_line(int fd)
{
	static char	*static_str[OPEN_MAX];
	char		*line;

	if (fd >= 0 && BUFFER_SIZE > 0 && fd < OPEN_MAX)
	{
		static_str[fd] = read_by_buffer(fd, static_str[fd]);
		if (!static_str[fd])
			return (NULL);
		line = find_line(static_str[fd]);
		static_str[fd] = save_thing(static_str[fd]);
		return (line);
	}
	return (NULL);
}
