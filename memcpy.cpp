


void * Memcpy(void *dst,const void *src,size_t n)
{
	assert(dst);
	assert(src);
	char * pdst=(char*)dst;
	char * psrc=(char*)src;

	while(n--)
	{
		*pdst++=*psrc++;

	}
	return dst;
}

void test()
{
	char src[10]={1,2,3,5,56,6};
	char dst[10]={0};
	Memcpy(dst,src,sizeof(src)/sizeof(src[0]));
	for(size_t i=0;i<sizeof(src)/sizeof(src[0]);i++)
	{
		cout<<src[i];
	}

}
int main()
{
	test();
	return 0;
}