unsigned long long	fact(unsigned long long n)
{
	unsigned long long res = 1;
	if (!(n))
		return (1);
	do
	{
		res *= n;
	}
	while (--n);
	return (res);
}
