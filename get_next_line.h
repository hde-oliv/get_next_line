#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define LB \n

int		get_next_line(int fd, char **line);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
