#include "get_next_line.h"

int	check_return_line(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save && save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	recherch_return_line(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *buffer)
{
	char	*new_save;
	int		i;
	int		j;
	int		len_tot;

	if (buffer == 0)
		return (save);
	len_tot = ft_len(save) + ft_len(buffer) + 1;
	printf("test len_tot : [%d]\n", len_tot);
	new_save = malloc(sizeof(char) * len_tot);
	if (!new_save)
		return (NULL);
	i = 0;
	while (save && save[i] != '\0')
	{
		new_save[i] = save[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		new_save[i + j] = buffer[j];
		j++;
	}
	new_save[i + j] = '\0';
	return (new_save);
}
