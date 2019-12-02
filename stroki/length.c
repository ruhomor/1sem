size_t	my_strlen(const char *s)
{
	char	*tmp = s;
	while (*tmp++);
	return (--tmp - s);
}
