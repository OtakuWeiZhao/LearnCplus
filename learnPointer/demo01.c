#include <stdio.h>
#include <string.h>

int main()
{
	char	string[15]	= "AragakiYuiGakki";
	char	c = string[0];
	char	*pointer;

	pointer = &string[0];
	printf( "ָ��pointer��ֵ��%p\n", pointer );

	int i;
	for ( i = 0; i < strlen( string ); i++ )
	{
		printf( "��%d���ַ���:%c\n", i + 1, *(pointer + i) );
	}
	return(0);
}
