package LibrarySystem.UI;

import java.awt.*;
import java.awt.event.*;
import java.util.*;

import javax.swing.*;
import javax.swing.table.*;

import LibrarySystem.sql.WJDsql;

public class ResultFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 窗口宽度
	final int WIDTH = 1550;
	// 窗口高度
	final int HEIGHT = 600;

	// 创建选择排序方式标签
	public JLabel Tag = new JLabel("排序方式：");

	// 创建选择排序方式下拉列表框
	String[] listData = new String[] { "以ISBN号排序", "以书名排序", "以出版日期排序" };
	public JComboBox<String> Sort = new JComboBox<String>(listData);

	// 查询结果列表的列标题
	public Vector<String> Title = new Vector<String>();

	// 查询结果列表的数据
	public Vector<Vector<String>> Data = new Vector<Vector<String>>();

	// 创建查询结果列表
	public MyTableModel Model = null;
	public JTable ResultList = null;

	JScrollPane ListScroll = new JScrollPane();

	public ResultFrame(String ISBN, String Title, String Author, String Publisher, String PublicationDate,
			String Type) {
		// 标题
		setTitle("查询结果界面");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		String[] str = new String[] { "ISBN", "书名", "作者", "出版社", "版号", "出版日期", "类型" };
		this.Title = new Vector<String>(Arrays.asList(str));
		this.Data = WJDsql.getBookList(ISBN, Title, Author, Publisher, PublicationDate, Type, "ISBN");

		Tag.setBounds(50, 20, 100, 30);
		Tag.setFont(new Font("华文楷体", Font.PLAIN, 18));
		this.add(Tag);

		// 排序选择栏
		Sort.setBounds(140, 20, 160, 30);
		Sort.setFont(new Font("华文楷体", Font.PLAIN, 18));
		this.add(Sort);

		// 查询结果表格
		Model = new MyTableModel();
		Model.setDataVector(this.Data, this.Title);
		ResultList = new JTable(Model);
		ResultList.setRowHeight(25);
		ResultList.setFont(new Font("华文楷体", Font.PLAIN, 18));
		ResultList.getTableHeader().setFont(new Font("华文楷体", Font.PLAIN, 18));
		ResultList.getTableHeader().setReorderingAllowed(false);
		ResultList.getTableHeader().setPreferredSize(new Dimension(1, 25));
		ResultList.setCellSelectionEnabled(false);

		// 设置单元格内容居中
		((DefaultTableCellRenderer) ResultList.getTableHeader().getDefaultRenderer())
				.setHorizontalAlignment(JLabel.CENTER);
		DefaultTableCellRenderer tcr = new DefaultTableCellRenderer();
		tcr.setHorizontalAlignment(JLabel.CENTER);
		ResultList.setDefaultRenderer(Object.class, tcr);
		ResultList.updateUI();

		// List滚动窗
		ListScroll.setViewportView(ResultList);
		ListScroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		ListScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		ListScroll.setBounds(50, 70, 1450, 460);
		this.add(ListScroll);

		// 下拉选项表的事件处理
		Sort.addItemListener(new ItemListener() {

			@Override
			public void itemStateChanged(ItemEvent e) {
				
				String[] str = new String[] { "ISBN", "书名", "作者", "出版社", "版号", "出版日期", "类型" };
				Vector<String> tTitle = new Vector<String>(Arrays.asList(str));
				Vector<Vector<String>> tList = null;
				
				if (e.getStateChange() == ItemEvent.SELECTED) {
					
					if (e.getItem().equals("以ISBN号排序")) {

						tList = WJDsql.getBookList(ISBN, Title, Author, Publisher,
								PublicationDate, Type, "ISBN");

					} else if (e.getItem().equals("以书名排序")) {

						tList = WJDsql.getBookList(ISBN, Title, Author, Publisher,
								PublicationDate, Type, "Title");

					} else if (e.getItem().equals("以出版日期排序")) {

						tList = WJDsql.getBookList(ISBN, Title, Author, Publisher,
								PublicationDate, Type, "PublicationDate");

					}
					
					Model.setDataVector(tList, tTitle);
					
				}

			}
		});
		
		setLayout(null);

		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);
	}

	// 自定义默认模板Table并设置无法编辑表格
	public class MyTableModel extends DefaultTableModel {
		private static final long serialVersionUID = 1L;

		// 禁止编辑表格
		@Override
		public boolean isCellEditable(int row, int column) {
			return false;
		}
	}
}
