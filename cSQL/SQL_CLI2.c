#include <sqlcli.h>;
void printAgeStudents()
{
	SQLHSTMT	stmt1;
	SQLHDBC		con1;
	SQLHENV		env1;
	SQLRETURN	ret1, ret2, ret3, ret4;
	ret1 = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env1 );
	if ( !ret1 )
		ret2 = SQLAllocHandle( SQL_HANDLE_DBC, env1, &col1 ) else exit;
	if ( !ret2 )
		ret3 = SQLConnect( col1, "dbs", SQL_NTS, "js", SQL_NTS, "xyz", SQL_NTS ) else exit;
	if ( !ret3 )
		ret4 = SQLAllocHandle( SQL_HANDLE_STMT, con1, &stmt1 ) else exit;
	SQLprepare( stmt1, "select SNAME, SEX from S where AGE = ?", SQL_NTS );
	prompt( "Enter a Age:", age );
	SQLBindParameter( stmt1, 1, SQL_SMALLINT, &age, 2, &fetchlen1 );
	ret1 = SQLExecute( stmt1 );
	if ( !ret1 )
	{
		SQLBindCol( stmt1, 1, SQL_CHAR, &sname, 9, &fetchlen1 );
		SQLBindCol( stmt1, 2, SQL_CHAR, &SEX, 2, &fetchlen2 );
		ret2 = SQLFetch( stmt1 );
		while ( !ret2 )
		{
			printf( sname, sex );
			ret2 = SQLFetch( stmt1 );
		}
	}
}
