#include "get_next_line.h"

char	*get_new_save(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = recherch_return_line(save);
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	tmp = NULL;
	ft_strcpy(tmp, save);
	free(save);
	save = malloc(sizeof(char) * (ft_len(tmp) - i + 1));
	if (!save)
		return (NULL);
	j = 0;
	while (tmp[i + j])
	{
		save[j] = tmp[i + j];
		j++;
	}
	save[j] = '\0';
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	if (!save || save[0] == 0)
		return (NULL);
	i = recherch_return_line(save);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*final_test(int check, char *save, char *buffer)
{
	char		*line;

	line = get_line(save);
	save = get_new_save(save);
	if (check == 0 && line == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	int			check;

	if (fd <= -1 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	if (!save)
		save = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!check_return_line(save) && check)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		buffer[check] = '\0';
		save = ft_strjoin(save, buffer);
	}
	return (final_test(check, save, buffer));
}
