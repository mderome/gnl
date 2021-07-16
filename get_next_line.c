#include "get_next_line.h"

char	*get_new_save(char *save)
{
	int		i;
	int		j;
	char	*tmp_save;
	char	*tmp;

	i = recherch_return_line(save);
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	tmp = save;
	tmp_save = malloc(sizeof(char) * (ft_len(save) - i + 1));
	if (!tmp_save)
		return (NULL);
	j = 0;
	while (tmp[i + j])
	{
		tmp_save[j] = tmp[i + j];
		j++;
	}
	tmp_save[j] = '\0';
	free(save);
	return (tmp_save);
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

char	*final_test(char *line, int check, char *save)
{
	if (check == 0 && line == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			check;
	char		*line;

	if (fd <= -1 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	if (!save)
		save = NULL;
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
	line = get_line(save);
	save = get_new_save(save);
	return (final_test(line, check, save));
}
