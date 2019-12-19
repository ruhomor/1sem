unsigned int		nod(unsigned int a, unsigned int b)
{
	unsigned int	c;

	if (!(a))
		return (b);
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return (a);
}
