int	func_hyper(float x, float y)
{
	float	f;

	if (y >= -2)
	{
		f = 1 / (x + 4) - 3;
		if ((y >= f) && (x >= -4))
			return (1);
	}
	return (0);
}
