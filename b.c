int foo2 (int * px, int * py)
{
	int	sum = *px + *py;
	printf("foo2 : res=%d x=%d y=%d\n", sum, ++*px, --*py);
	return (sum);
}
