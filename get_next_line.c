#include "get_next_line.h"
#include <unistd.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	void	*p;

	i = ft_strlen(s1) + 1;
	p = malloc(i * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, i);
	return (p);
}

static int	newline_handler(char **string, char **line)
{
	int		i;
	char	*temp_str;

	i = 0;
	while ((*string)[i] != '\n')
		if ((*string)[i++] == '\0')
			return (0);
	(*string)[i] = 0;
	*line = ft_strdup(*string);
	if (!*line)
		return (-1);
	temp_str = *string;
	*string = ft_strdup(&(*string)[i+1]);
	free(temp_str);
	return (1);
}

static int	eof_handler(char **string, char **line)
{
	if (*string == NULL)
		return (0);
	*line = ft_strdup(*string);
	free(*string);
	*string = NULL;
	return (1);
}

static int	get_line(int fd, char **string, char *slice, char **line)
{
	char	*temp;
	int 	read_val;

	read_val = read(fd, slice, BUFFER_SIZE);
	while (read_val > 0)
	{
		if (*string)
		{
			temp = *string;
			*string = ft_strjoin(*string, slice);
			free(temp);
		}
		else
			*string = ft_strdup(slice);
		if (newline_handler(string, line) == 1)
			return (1);
		if (*string == NULL)
			return (-1);
		read_val = read(fd, slice, BUFFER_SIZE);
	}
	return (eof_handler(string, line));
}

int	get_next_line(int fd, char **line)
{
	char			slice[BUFFER_SIZE + 1];
	static char		*string;
	int				result;

	if ((fd >= FD_MAX || fd < 0) || !line || read(fd, slice, 0) < 0)
		return (-1);
	ft_bzero(slice, BUFFER_SIZE + 1);
	result = get_line(fd, &string, slice, line);
	return (result);
}
