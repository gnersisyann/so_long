#include "libft.h"

static void	ft_strjoin_helper(char *res, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;

	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res)
		return (NULL);
	ft_strjoin_helper(res, s1, s2);
	res[sizetotal] = '\0';
	return (res);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *string, size_t n)
{
	char	*res;
	char	*start;

	if (!n)
		return (NULL);
	res = (char *)malloc(n + 1);
	if (!res)
		return (NULL);
	start = res;
	while (*string && n-- > 0)
	{
		*res = *string;
		res++;
		string++;
	}
	*res = '\0';
	return (start);
}
