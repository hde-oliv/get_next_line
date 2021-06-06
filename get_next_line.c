#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int	newline_handler(char **string, char **line)
{
	int		i;
	char	*temp_str;

	i = 0;
	while ((*string)[i] != '\n')
		if ((*string)[i++] == '\0')
			return (0);
	*line = ft_substr(*string, 0, i);
	temp_str = *string;
	*string = ft_substr((*string + i + 1), 0, BUFFER_SIZE - i - 1);
	free(temp_str);
	return (1);
}

int	eof_handler(char **string, char **line)
{
	int		i;

	if (*string == NULL)
		return (0);
	i = ft_strlen(*string);
	*line = ft_substr(*string, 0, i);
	free(*string);
	*string = NULL;
	return (1);
}

int	get_line(int fd, char **string, char *slice, char **line)
{
	char	*temp;

	while (read(fd, slice, BUFFER_SIZE) > 0)
	{
		if (*string)
		{
			temp = *string;
			*string = ft_strjoin(*string, slice);
			free(temp);
		}
		else
			*string = ft_substr(slice, 0, BUFFER_SIZE + 1);
		if (newline_handler(string, line))
			return (1);
	}
	return (eof_handler(string, line));
}

int	get_next_line(int fd, char **line)
{
	char			*slice;
	static char		*string;

	if (fd >= FD_SETSIZE || fd < 0 || !line)
		return (-1);
	slice = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	slice[BUFFER_SIZE] = '\0';
	if (get_line(fd, &string, slice, line))
		return (1);
	else
		return (0);
}
