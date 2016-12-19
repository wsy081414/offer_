void * Memmove(void *dst,const void *src,size_t n)
{
	assert(dst);
	assert(src);
	char* pdst=(char *)dst;
	char* psrc=(char *)src;
	//判断重叠
	if((pdst>psrc)&&pdst<psrc+n)
	{
		while(n--)
		{
			*(pdst+n)=*(psrc+n);
		}
	}
	else
	{
		while(n--)
		{
			*pdst++=*psrc++;
		}
	}
	return dst;
}