/* 必须在C程序中包含组成SQL/CLI的函数库,该库名为sqlcli.h */
#include <sqlcli.h>;
void printAge()
{
	/* 语句记录Statement Record */
	SQLHSTMT stmt1;
	/* 连接记录Connection Record */
	SQLHDBC con1;
	/* 环境记录 Environment Record */
	SQLHENV env1;
	/* 如果返回值是0,就表示成功执行了函数调用 */
	SQLRETURN ret1, ret2, ret3, ret4;


	/*
	 * 使用SQLAllocHandle函数在程序中返回一个环境记录,由于环境记录未包含在任何其他记录
	 * 中,因此在创建环境是,参数<handle_1>是一个空句柄SQL_NULL_HANDLE(空指针).此时创建
	 * 环境记录的句柄(指针)返回至变量env1中.
	 */
	ret1 = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env1 );


	/*
	 * 使用SQLAllocHandle函数在程序中建立了一个连接记录,所创建的连接记录有句柄col,并包含
	 * 在环境env1中.
	 */
	if ( !ret1 )
		ret2 = SQLAllocHandle( SQL_HANDLE_DBC, env1, &con1 ) else exit;


	/*
	 * 使用SQL/CLI的SQLConnect函数在col1中建立一个特定服务器的数据库连接.此处,我们所
	 * 连接的数据库名为"dbs", 登录的账户名和口令分别是"js"和"xyz".
	 */
	if ( !ret2 )
		ret3 = SQLConnect( con1, "dbs", SQL_NTS, "JS", SQL_NTS, "xyz",
				   SQL_NTS ) else exit;


	/*
	 * 使用SQLAllocHandle函数在程序中简历一个语句记录.所创建的语句记录的句柄是stmt1,
	 * 病使用连接con1
	 */
	if ( !ret3 )
		ret4 = SQLAllocHandle( SQL_HANDLE_STMT, con1, &stmt1 ) else exit;


	/*
	 * 使用SQL/CLI的函数SQLprepare来准备SQL语句,将SQL语句串赋给语句句柄stmt1.行中
	 * "?"表示一个语句参数,这个只要在运行时才能确定,通常要将其绑定至一个C程序变量.一般
	 * 可能会有多个参数.可以根据语句中问号出现的次序来区分这些参数.SQLprepare中的最后
	 * 一个参数应给出SQL语句穿的长度(字节数),但键入关键字SQL_NTS,这就表示包括此查询的
	 * 字符串是一个NULL终止串,这样SQL就能自动计算字符串的长度.这也适用于函数调用中其他
	 * 字符串参数
	 */
	SQLprepare( stmt1, " select SNAME , AGE from S where S# = ?", SQL_NTS );
	/* 输入s#的值 */
	prompt( "Enter a Student Number:" s # );


	/*
	 * 将参数通过适用SQL/CLI函数SQLBindParameter绑定到程序变量s#.如果SQL语句有n个参数,
	 * 就应当有n个SQLBindParameter函数调用,每个函数调用都对应一个不同的参数位置(1, 2, n).
	 */
	SQLBindParameter( stmt1, 1, SQL_CHAR, &s # , 5, &fetchlen1 );


	/*
	 * 在完成上述准备后,适用SQLExecute函数执行有句柄stmt1引用的SQL语句,应注意,尽管查询在
	 * 该行执行,但查询结果尚未赋给任何C程序变量
	 */
	ret1 = SQLExecute( stmt1 );
	/* 为了确定查询结果返回到哪里,一种常用的技术是绑定列(Bound Column)方法 */
	if ( !ret1 )
	{
		/* 使用SQLBindCol函数将查询结果中的两个列分别绑定到C程序变量Sname和age */
		SQLBindCol( stmt1, 1, SQL_CHAR.& sname, 9, &fetchlen1 );
		SQLBindCol( stmt1, 2, SQL_SMALLINT, &age, 2, &fetchlen2 );


		/*
		 * 为了将列值检索到C程序变量中,用到了SQLFetch函数.此函数与嵌入式SQL中的FETCH命令
		 * 类似.如果查询结果有一个元组集,各SQLFetch调用将获取下一个元组,并将其列值返回到
		 * 所绑定的程序变量中.如果再无更多元组,SQLFetch将返回一个(非0)的异常代码
		 */
		ret2 = SQLFetch( stmt1 );
		if ( !ret2 )
			printf( s # , sname, age );
		else printf( " The Student Number does not exist:", s # );
	}
	return 0
}
