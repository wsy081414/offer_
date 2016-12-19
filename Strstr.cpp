
char *Strstr(const char *dst, const char* src)
{
	assert(dst);
	assert(src);

	const char* pdst = dst;
	const char* psrc = src;
	const char* start = NULL;
	while (*pdst)
	{
		start = pdst;

		while (*pdst&&*psrc&&*pdst == *psrc)
		{
			pdst++;
			psrc++;
		}
		if (*psrc == '\0')
		{
			return (char *)start;
		}
		pdst = start + 1;
		psrc = src;
	}

	return NULL;
}