/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:00:42 by fnagy             #+#    #+#             */
/*   Updated: 2024/10/29 10:28:43 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *) s);
}

static char	*fill_stash(int fd, char *stash, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(stash), free(buffer), NULL);
		buffer[b_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*set_line(char *stash)
{
	char	*line;
	char	*new_line;
	ssize_t	i;

	i = 0;
	line = NULL;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	new_line = ft_substr(stash, 0, i + (stash[i] == '\n'));
	if (new_line)
		line = malloc((ft_strlen(new_line) + 1) * sizeof(char));
	if (!line)
		return (free(new_line), NULL);
	i = -1;
	while (new_line[++i])
		line[i] = new_line[i];
	line[i] = '\0';
	free(new_line);
	return (line);
}

static char	*shift_stash(char *stash, size_t len)
{
	char	*new_stash;
	size_t	stash_len;

	if (!stash || !*stash)
		return (NULL);
	stash_len = ft_strlen(stash);
	if (len >= stash_len)
		return (NULL);
	new_stash = ft_substr(stash, len, stash_len - len);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_stash;
	char		*line;
	char		*buffer;

	new_stash = NULL;
	line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), stash = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	stash = fill_stash(fd, stash, buffer);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	new_stash = shift_stash(stash, ft_strlen(line));
	free(stash);
	stash = new_stash;
	return (line);
}
