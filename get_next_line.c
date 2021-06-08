#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 60
#endif
#define MAX_FD 256

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
	temp_str = *string;
	*string = ft_strdup(&(*string)[i + 1]);
	free(temp_str);
	return (1);
}

static int	eof_handler(char **string, char **line)
{
	if (*string == (void *)2)
		return (0);
	else if (*string == NULL)
	{
		*line = ft_strdup("");
		free(*string);
		*string = (void *)2;
		return (0);
	}
	*line = ft_strdup(*string);
	free(*string);
	*string = (void *)2;
	return (1);
}

static int	get_line(int fd, char **string, char *slice, char **line)
{
	char	*temp;
	int		read_val;

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
		if (newline_handler(string, line))
			return (1);
		read_val = read(fd, slice, BUFFER_SIZE);
	}
	return (eof_handler(string, line));
}

int	get_next_line(int fd, char **line)
{
	char			slice[BUFFER_SIZE + 1];
	static char		*string;
	int				res;

	if ((fd >= MAX_FD || fd < 0) || !line)
		return (-1);
	ft_bzero(slice, BUFFER_SIZE + 1);
	res = get_line(fd, &string, slice, line);
	return (res);
}
