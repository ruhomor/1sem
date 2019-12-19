struct Rect * max(struct Rect * pa, struct Rect * pb)
{
	int sa;
	int sb;

	sa = pa->width * pa->height;
	sb = pb->width * pb->height;
	if (sa > sb)
		return (pa);
	return (pb);
}
