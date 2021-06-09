#include "get_next_line_bonus.h"

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
	*string = ft_strdup(&(*string)[i + 1]);
	if (!*string)
		return (-1);
	free(temp_str);
	return (1);
}

static int	eof_handler(char **string, char **line)
{
	char	*temp_str;

	if (*string == NULL)
	{
		*line = ft_strdup("");
		if (!*line)
			return (-1);
		return (0);
	}
	if (newline_handler(string, line) == 1)
		return (1);
	*line = ft_strdup(*string);
	if (!*line)
		return (-1);
	temp_str = *string;
	free(temp_str);
	*string = NULL;
	return (0);
}

static int	get_line(int fd, char **string, char *slice, char **line)
{
	char	*temp;

	while (read(fd, slice, BUFFER_SIZE) > 0)
	{
		if (*string)
		{
			temp = *string;
			*string = ft_strjoin(*string, slice);
			if (!string)
				return (-1);
			free(temp);
		}
		else
		{
			*string = ft_strdup(slice);
			if (!string)
				return (-1);
		}
		if (newline_handler(string, line) == 1)
			return (1);
		if (!*line)
			return (-1);
		ft_bzero(slice, BUFFER_SIZE + 1);
	}
	return (eof_handler(string, line));
}

int	get_next_line(int fd, char **line)
{
	char			slice[BUFFER_SIZE + 1];
	static char		*string[MAX_FD];
	int				res;

	if ((fd >= MAX_FD || fd < 0) || !line)
		return (-1);
	ft_bzero(slice, BUFFER_SIZE + 1);
	res = get_line(fd, &(string[fd]), slice, line);
	return (res);
}
