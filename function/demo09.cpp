#include <iostream>

using namespace std;

float *input( int & ); /* ��������ָ��ĺ��� */


float *input( int &n ) /* ����ָ��ĺ��� */
{
	cout << "Input number:";                        /* ѯ�������������� */
	cin >> n;
	if ( n <= 0 )
		return(NULL);                           /* ���벻�������˳� */
	float *buf = new float[n];                      /* ����������������ռ� */
	if ( buf == 0 )
		return(NULL);                           /* û�����뵽���˳� */
	for ( int i = 0; i < n; i++ )                   /* ������������ */
		cin >> buf[i];
	return(buf);                                    /* ����ָ�� */
}


int main()
{
	int	num;
	float	*data;                                  /* ������input����һ�µ�ָ�� */
	data = input( num );                            /* ���ú���,����ָ�븳��data */
	if ( data )                                     /* data����,�����ָ���� */
	{
		for ( int i = 0; i < num; i++ )         /* ʹ��ָ����±���ʽ */
			cout << data[i] << " ";         /* ѭ����� */
		delete data;                            /* �ͷ��ڴ�ռ� */
	}
	return(0);
}
