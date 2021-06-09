#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define MAX_FD 256

int		get_next_line(int fd, char **line);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);

#endif
