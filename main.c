#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int ft_init(t_fdf *fdf)
{
	fdf->xZ = 3;
	fdf->a = 0;
	fdf->b = 0;
	fdf->c = 0;
	if (tab_filler(fdf) == -1)
	{
		ft_putendl("Error");
		return (-1);
	}
	return (0);
}

/* void ft_printer(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->lines)
	{
		j = 0;
		while(j < fdf->chars)
		{
			printf("%d-", fdf->map[i][j]);
			printf("%d ", fdf->color[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
} */

int	main(int ac, char *av[])
{
	t_fdf fdf;

	if (ac != 2)
	{
		ft_putendl("usage: fdf \"name of file\"\n");
		return (1);
	}
	if (((fdf.fd = open(av[1], O_RDONLY)) == - 1))
	{
		ft_putendl("error fd\n");
		return (1);
	}
	fdf.name = av[1];
	if (ft_init(&fdf))
		return (1);
    if ((setup_mlx(&fdf)))
		free_map_color(&fdf);
	return (0);
}
