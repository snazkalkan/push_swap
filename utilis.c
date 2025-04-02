#include <unistd.h>

static void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (words[i])
			free(words[i]);
		i++;
	}
	free(words);
}

static int	count_words(const char *s, char delimiter)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == delimiter)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char **s, char delimiter)
{
	const char	*start;
	size_t		len;

	while (**s && **s == delimiter)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != delimiter)
		len++;
	*s += len;
	return (ft_substr(start, 0, len));
}

char	**ft_split(const char *s, char delimiter)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, delimiter);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = extract_word(&s, delimiter);
		if (!result[i])
		{
			free_words(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
void	ft_putstr(char *str)
{
    int i;

    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		sb = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		sb = malloc((len + 1) * sizeof(char));
	if (!sb)
		return (NULL);
	ft_strlcpy(sb, s + start, len + 1);
	return (sb);
}
