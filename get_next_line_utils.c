#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	org_size;

	i = 0;
	j = dstsize;
	while (j-- != 0 && dst[i] != '\0')
		i++;
	j = dstsize - i;
	if (j == 0)
		return (ft_strlen(src) + i);
	j = 0;
	org_size = i;
	while (i < (dstsize - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + org_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((i < (dstsize - 1)) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *) malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcat(p, s2, s1_len + s2_len + 1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s);
	if (start < i)
	{
		if (i > len)
			p = (char *) malloc(sizeof(char) * len + 1);
		else
			p = (char *) malloc(sizeof(char) * i + 1);
		if (p == NULL)
			return (NULL);
		ft_strlcpy(p, &s[start], len + 1);
	}
	else
	{
		p = (char *) malloc(sizeof(char) * 1);
		if (p == NULL)
			return (NULL);
		ft_strlcpy(p, "", 1);
	}
	return (p);
}
