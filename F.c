#include <stdio.h>

int	main()
{
	double	x;
	double	y;
	double	xres;
	double	yres;
	int	n;
	int	i;
	FILE	*fael;

	fael = fopen("input", "r");
	n = 3;
	i = n;
	xres = 0;
	yres = 0;
	while (i--)
	{
		fscanf(fael, "%lf%lf", &x, &y);
		xres += x;
		yres += y;
	}
	fclose(fael);
	fael = fopen("output", "w");
	xres /= n;
	yres /= n;
	fprintf(fael, "%lf %lf", xres, yres);
	return (0);
}
