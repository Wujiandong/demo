package LibrarySystem.sql;

import java.sql.*;
import java.text.*;
import java.util.*;
import java.util.Date;

public class WJDsql {

	// JDBC驱动名及数据库 URL
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
	static final String DB_URL = "jdbc:mysql://localhost:3306/library?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC";

	// 数据库的用户名与密码
	static final String USER = "root";
	static final String PASS = "zxc123456";

	// 日期格式
	static final SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");

	/**
	 * 方法名：getBookList
	 * 参数：书籍的六个字段
	 * 功能：通过相关字段获取查询到的列表List
	 * 返回值：二维数组List
	 */
	public static Vector<Vector<String>> getBookList(String ISBN, String title, String Authors, String publisher,
			String publicationDate, String type, String Sort) {

		// 存放查询结果的容器
		Vector<Vector<String>> List = new Vector<Vector<String>>();

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行查询
			stmt = conn.createStatement();

			String sql = null;
			if (Sort.equals("ISBN")) {
				
				sql = String.format(
						"SELECT * FROM books WHERE ISBN like '%%%s%%' and Title like '%%%s%%' and Authors like '%%%s%%' and Publisher like '%%%s%%' and PublicationDate like '%%%s%%' and Type like '%%%s%%' ORDER BY %s ;",
						ISBN, title, Authors, publisher, publicationDate, type, Sort);
			
			} else if (Sort.equals("Title")) {
			
				sql = String.format(
						"SELECT * FROM books WHERE ISBN like '%%%s%%' and Title like '%%%s%%' and Authors like '%%%s%%' and Publisher like '%%%s%%' and PublicationDate like '%%%s%%' and Type like '%%%s%%' ORDER BY %s DESC;",
						ISBN, title, Authors, publisher, publicationDate, type, Sort);
			
			} else if (Sort.equals("PublicationDate")) {
			
				sql = String.format(
						"SELECT * FROM books WHERE ISBN like '%%%s%%' and Title like '%%%s%%' and Authors like '%%%s%%' and Publisher like '%%%s%%' and PublicationDate like '%%%s%%' and Type like '%%%s%%' ORDER BY %s ;",
						ISBN, title, Authors, publisher, publicationDate, type, Sort);
			
			}

			ResultSet result = stmt.executeQuery(sql);

			// 展开结果集数据库
			while (result.next()) {

				// 通过字段检索
				Long rISBN = result.getLong("ISBN");
				String rTitle = result.getString("Title");
				String rAuthors = result.getString("Authors");
				String rPublisher = result.getString("Publisher");
				Long rEditionNumber = result.getLong("EditionNumber");
				Date rPublicationDate = new Date(result.getDate("PublicationDate").getTime());
				String rType = result.getString("Type");

				Vector<String> Temp = new Vector<String>();
				Temp.add(rISBN.toString());
				Temp.add(rTitle);
				Temp.add(rAuthors);
				Temp.add(rPublisher);
				Temp.add(rEditionNumber.toString());
				Temp.add(formatter.format(rPublicationDate));
				Temp.add(rType);

				List.add(Temp);
			}

			// 完成后关闭
			result.close();
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}

		return List;
	}

	
	/**
	 * 方法名：checkBook
	 * 功能：通过图书名获取对应的ISBN
	 * 参数：书名
	 * 返回值：ISBN
	 */
	public static Long checkBook(String Title) {

		// ISBN用于记录查询到的图书的ISBN
		Long ISBN = null;

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行查询
			stmt = conn.createStatement();
			String sql = String.format("SELECT ISBN FROM books WHERE Title = '%s' ;", Title);
			ResultSet result = stmt.executeQuery(sql);

			// 展开结果集数据库
			while (result.next()) {

				// 通过字段检索
				ISBN = result.getLong("ISBN");

			}

			// 完成后关闭
			result.close();
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}

		return ISBN;
	}

	/**
	 * 方法名：checkBorrowed
	 * 功能：检查该书是否被借出，并返回归还日期
	 * 参数：书名
	 * 返回值：归还日期
	 */
	public static String checkBorrowed(String Title) {

		// str用于保存通过查询得到的归还日期
		String str = null;

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行查询
			stmt = conn.createStatement();

			String sql = String.format(
					"SELECT ReturnDate FROM record JOIN books ON record.ISBN = books.ISBN WHERE Title = '%s' ;", Title);

			ResultSet result = stmt.executeQuery(sql);

			// 展开结果集数据库
			while (result.next()) {

				// 通过字段检索
				Date rReturnDate = new Date(result.getDate("ReturnDate").getTime());

				str = formatter.format(rReturnDate);

			}

			// 完成后关闭
			result.close();
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}

		return str;
	}

	/**
	 * 方法名：checkLimits
	 * 功能：检查借阅人的限借数量
	 * 参数：借阅人的ReaderID
	 * 返回值：Limits
	 */
	public static Long checkLimits(int ReaderID) {

		// i用于保存通过查询得到的限借数量
		Long i = new Long(0);

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行查询
			stmt = conn.createStatement();
			String sql = String.format("SELECT Limits FROM Reader WHERE ReaderID = '%d' ;", ReaderID);
			ResultSet result = stmt.executeQuery(sql);

			// 展开结果集数据库
			while (result.next()) {

				// 通过字段检索
				i = result.getLong("Limits");

			}

			// 完成后关闭
			result.close();
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}

		return i;
	}

	/**
	 * 方法名：updateLimits
	 * 功能：更新借阅人的限借数量
	 * 参数：借阅人的ReaderID和更改数量t
	 * 返回值：无
	 */
	public static void updateLimits(int ReaderID, int t) {

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行更新
			stmt = conn.createStatement();
			String sql = String.format("UPDATE Reader SET Limits = Limits + (%d) WHERE ReaderID = %d; ", t, ReaderID);
			stmt.executeUpdate(sql);

			// 完成后关闭
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}
	}
	
	/**
	 * 方法名：insertRecord
	 * 功能：向Record表中插入一条记录
	 * 参数：书名和借阅人ID
	 * 返回值：无
	 */
	public static void insertRecord(String Title, int ReaderID) {

		// 获取借书日期和还书日期
		Date borrowDate = new Date();
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(borrowDate);
		calendar.set(Calendar.MONTH, calendar.get(Calendar.MONTH) + 1); // 设置为后一个月
		Date returnDate = calendar.getTime();

		// 获取所借书的ISBN
		Long ISBN = checkBook(Title);

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行更新
			stmt = conn.createStatement();

			String sql = String.format(
					"INSERT INTO record (ISBN,ReaderID,BorrowingDate,ReturnDate) VALUES (%d,%d,'%s','%s');", ISBN,
					ReaderID, formatter.format(borrowDate), formatter.format(returnDate));

			stmt.executeUpdate(sql);

			// 完成后关闭
			stmt.close();
			conn.close();

		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}
	}

	/**
	 * 方法名：deleteRecord
	 * 功能：删除Record中的一条记录
	 * 参数：书名和借阅人的ID
	 * 返回值：无
	 */
	public static void deleteRecord(String Title, int ReaderID) {

		// 获取书籍的ISBN
		Long ISBN = checkBook(Title);

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行更新
			stmt = conn.createStatement();
			String sql = String.format("DELETE FROM record WHERE ISBN = %d and ReaderID = %d", ISBN, ReaderID);
			stmt.executeUpdate(sql);

			// 完成后关闭
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}
	}
	public static Vector<Vector<String>> getRecordList(Integer ReaderID) {

		// List用于记录查询到的借阅记录的所有书名
		Vector<Vector<String>> List = new Vector<Vector<String>>();

		// MySQL数据库操作部分
		Connection conn = null;
		Statement stmt = null;

		try {
			// 注册 JDBC 驱动
			Class.forName(JDBC_DRIVER);

			// 打开链接
			System.out.println("连接数据库...");
			conn = DriverManager.getConnection(DB_URL, USER, PASS);

			// 执行查询
			stmt = conn.createStatement();
			String sql = String.format("SELECT Title FROM record JOIN books ON record.ISBN = books.ISBN WHERE ReaderID = %d;", ReaderID);
			ResultSet result = stmt.executeQuery(sql);

			// 展开结果集数据库
			while (result.next()) {

				Vector<String> Temp = new Vector<String>();
				// 通过字段检索并记录到List中
				Temp.add(result.getString("Title"));
				List.add(Temp);

			}

			// 完成后关闭
			result.close();
			stmt.close();
			conn.close();
		} catch (SQLException se) {

			// 处理 JDBC 错误
			se.printStackTrace();

		} catch (Exception e) {

			// 处理 Class.forName 错误
			e.printStackTrace();

		} finally {

			// 关闭资源
			try {
				if (stmt != null)
					stmt.close();
			} catch (SQLException se2) {
				// 什么都不做
			}
			try {
				if (conn != null)
					conn.close();
			} catch (SQLException se) {
				se.printStackTrace();
			}
		}

		return List;
	}

}
