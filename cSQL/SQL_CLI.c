/* ������C�����а������SQL/CLI�ĺ�����,�ÿ���Ϊsqlcli.h */
#include <sqlcli.h>;
void printAge()
{
	/* ����¼Statement Record */
	SQLHSTMT stmt1;
	/* ���Ӽ�¼Connection Record */
	SQLHDBC con1;
	/* ������¼ Environment Record */
	SQLHENV env1;
	/* �������ֵ��0,�ͱ�ʾ�ɹ�ִ���˺������� */
	SQLRETURN ret1, ret2, ret3, ret4;


	/*
	 * ʹ��SQLAllocHandle�����ڳ����з���һ��������¼,���ڻ�����¼δ�������κ�������¼
	 * ��,����ڴ���������,����<handle_1>��һ���վ��SQL_NULL_HANDLE(��ָ��).��ʱ����
	 * ������¼�ľ��(ָ��)����������env1��.
	 */
	ret1 = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env1 );


	/*
	 * ʹ��SQLAllocHandle�����ڳ����н�����һ�����Ӽ�¼,�����������Ӽ�¼�о��col,������
	 * �ڻ���env1��.
	 */
	if ( !ret1 )
		ret2 = SQLAllocHandle( SQL_HANDLE_DBC, env1, &con1 ) else exit;


	/*
	 * ʹ��SQL/CLI��SQLConnect������col1�н���һ���ض������������ݿ�����.�˴�,������
	 * ���ӵ����ݿ���Ϊ"dbs", ��¼���˻����Ϳ���ֱ���"js"��"xyz".
	 */
	if ( !ret2 )
		ret3 = SQLConnect( con1, "dbs", SQL_NTS, "JS", SQL_NTS, "xyz",
				   SQL_NTS ) else exit;


	/*
	 * ʹ��SQLAllocHandle�����ڳ����м���һ������¼.������������¼�ľ����stmt1,
	 * ��ʹ������con1
	 */
	if ( !ret3 )
		ret4 = SQLAllocHandle( SQL_HANDLE_STMT, con1, &stmt1 ) else exit;


	/*
	 * ʹ��SQL/CLI�ĺ���SQLprepare��׼��SQL���,��SQL��䴮���������stmt1.����
	 * "?"��ʾһ��������,���ֻҪ������ʱ����ȷ��,ͨ��Ҫ�������һ��C�������.һ��
	 * ���ܻ��ж������.���Ը���������ʺų��ֵĴ�����������Щ����.SQLprepare�е����
	 * һ������Ӧ����SQL��䴩�ĳ���(�ֽ���),������ؼ���SQL_NTS,��ͱ�ʾ�����˲�ѯ��
	 * �ַ�����һ��NULL��ֹ��,����SQL�����Զ������ַ����ĳ���.��Ҳ�����ں�������������
	 * �ַ�������
	 */
	SQLprepare( stmt1, " select SNAME , AGE from S where S# = ?", SQL_NTS );
	/* ����s#��ֵ */
	prompt( "Enter a Student Number:" s # );


	/*
	 * ������ͨ������SQL/CLI����SQLBindParameter�󶨵��������s#.���SQL�����n������,
	 * ��Ӧ����n��SQLBindParameter��������,ÿ���������ö���Ӧһ����ͬ�Ĳ���λ��(1, 2, n).
	 */
	SQLBindParameter( stmt1, 1, SQL_CHAR, &s # , 5, &fetchlen1 );


	/*
	 * ���������׼����,����SQLExecute����ִ���о��stmt1���õ�SQL���,Ӧע��,���ܲ�ѯ��
	 * ����ִ��,����ѯ�����δ�����κ�C�������
	 */
	ret1 = SQLExecute( stmt1 );
	/* Ϊ��ȷ����ѯ������ص�����,һ�ֳ��õļ����ǰ���(Bound Column)���� */
	if ( !ret1 )
	{
		/* ʹ��SQLBindCol��������ѯ����е������зֱ�󶨵�C�������Sname��age */
		SQLBindCol( stmt1, 1, SQL_CHAR.& sname, 9, &fetchlen1 );
		SQLBindCol( stmt1, 2, SQL_SMALLINT, &age, 2, &fetchlen2 );


		/*
		 * Ϊ�˽���ֵ������C���������,�õ���SQLFetch����.�˺�����Ƕ��ʽSQL�е�FETCH����
		 * ����.�����ѯ�����һ��Ԫ�鼯,��SQLFetch���ý���ȡ��һ��Ԫ��,��������ֵ���ص�
		 * ���󶨵ĳ��������.������޸���Ԫ��,SQLFetch������һ��(��0)���쳣����
		 */
		ret2 = SQLFetch( stmt1 );
		if ( !ret2 )
			printf( s # , sname, age );
		else printf( " The Student Number does not exist:", s # );
	}
	return 0
}
