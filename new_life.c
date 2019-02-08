#include "fdf.h"

int ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((!(ft_isdigit(str[i]))) && (i == 0 &&(str[i] != '-')))
			return (0);
		i++;
	}
	return (1);
}

int line_val(t_fdf *fdf, char *line)
{
	int i;
	char **tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		if (!(ft_isnum(tab[i])))
			return (-1);
		i++;
	}
	if (fdf->lines == 0)
		fdf->chars = i;
	else
	{
		if (i != fdf->chars)
			return (-1);
	}
	free(line);
	ft_arrclr(tab);
	fdf->lines++;
	return (0);
}

int ft_put_sizes(t_fdf *fdf)
{
	char *line;
	int ret;

	line = NULL;
	fdf->lines = 0;
	fdf->chars = 0;
	while ((ret = get_next_line(fdf->fd, &line)) == 1)
	{
		if (line_val(fdf, line) == -1)
			return (-1);
	}
	fdf->offset = WIN_HEIGHT / (2 * fdf->lines) + 2;
	fdf->pad_X = WIN_WIDTH / 2;
	fdf->pad_Y = WIN_HEIGHT / 6;
	return (0);
}

int tab_make(t_fdf *fdf)
{
	if (ft_put_sizes(fdf) == -1)
		return (-1);
	fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->lines);
	fdf->color = (int **)ft_memalloc(sizeof(int *) * fdf->lines);
	close(fdf->fd);
	fdf->fd = open(fdf->name, O_RDONLY);
	return (0);
}

int get_cords(t_fdf *fdf)
{
	int i;
	int j;
	int ret;
	char *line;
	char **tab;

	i = 0;
	while ((ret = get_next_line(fdf->fd, &line)) > 0)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		fdf->map[i] = ft_memalloc(sizeof(int) * fdf->chars);
		fdf->color[i] = ft_memalloc(sizeof(int) * fdf->chars);
		while (tab[j] != NULL)
		{
			fdf->map[i][j] = ft_atoi(tab[j]);
			fdf->color[i][j] = ft_getcol(tab[j]);
			j++;
		}
		ft_arrclr(tab);
		i++;
	}
	return (0);
}

int tab_filler(t_fdf *fdf)
{
	if (tab_make(fdf) == -1)
		return (-1);
	if (get_cords(fdf) == -1)
		return (-1);
	return (0);
}
