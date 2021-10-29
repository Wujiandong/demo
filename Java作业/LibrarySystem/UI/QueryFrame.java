package LibrarySystem.UI;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Vector;

import LibrarySystem.sql.WJDsql;

public class QueryFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 窗口宽度
	final int WIDTH = 720;
	// 窗口高度
	final int HEIGHT = 250;

	// 创建ISBN标签
	public JLabel ISBNLabel = new JLabel("ISBN ");
	// 创建书名标签
	public JLabel TitleLabel = new JLabel("书名  ");
	// 创建作者标签
	public JLabel AuthorsLabel = new JLabel("作者");
	// 创建出版社标签
	public JLabel PublisherLabel = new JLabel("出版社");
	// 创建出版日期标签
	public JLabel PublicationDateLabel = new JLabel("出版日期");
	// 创建类型标签
	public JLabel TypeLabel = new JLabel("类型");

	// 创建ISBN输入框
	public JTextField ISBN = new JTextField();
	// 创建书名输入框
	public JTextField Title = new JTextField();
	// 创建作者输入框
	public JTextField Authors = new JTextField();
	// 创建出版社输入框
	public JTextField Publisher = new JTextField();
	// 创建出版日期输入框
	public JTextField PublicationDate = new JTextField();
	// 创建类型输入框
	public JTextField Type = new JTextField();

	// 创建查询按钮
	public JButton query = new JButton("查询");

	public QueryFrame() {
		// 标题
		setTitle("查询");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		ISBNLabel.setBounds(45, 30, 70, 30);
		TitleLabel.setBounds(265, 30, 70, 30);
		AuthorsLabel.setBounds(497, 30, 70, 30);
		PublisherLabel.setBounds(40, 80, 70, 30);
		PublicationDateLabel.setBounds(250, 80, 100, 30);
		TypeLabel.setBounds(497, 80, 70, 30);

		ISBN.setBounds(95, 30, 120, 30);
		Title.setBounds(320, 30, 120, 30);
		Authors.setBounds(542, 30, 120, 30);
		Publisher.setBounds(95, 80, 120, 30);
		PublicationDate.setBounds(320, 80, 120, 30);
		Type.setBounds(542, 80, 120, 30);

		query.setBounds(320, 140, 120, 40);
		query.setFont(new Font("宋体", Font.PLAIN, 20));

		ISBNLabel.setFont(new Font("宋体", Font.PLAIN, 15));
		TitleLabel.setFont(new Font("宋体", Font.PLAIN, 15));
		AuthorsLabel.setFont(new Font("宋体", Font.PLAIN, 15));
		PublisherLabel.setFont(new Font("宋体", Font.PLAIN, 15));
		PublicationDateLabel.setFont(new Font("宋体", Font.PLAIN, 15));
		TypeLabel.setFont(new Font("宋体", Font.PLAIN, 15));

		ISBN.setFont(new Font("宋体", Font.PLAIN, 15));
		Title.setFont(new Font("宋体", Font.PLAIN, 15));
		Authors.setFont(new Font("宋体", Font.PLAIN, 15));
		Publisher.setFont(new Font("宋体", Font.PLAIN, 15));
		PublicationDate.setFont(new Font("宋体", Font.PLAIN, 15));
		Type.setFont(new Font("宋体", Font.PLAIN, 15));

		query.addActionListener(new ActionListener() {

			String strISBN = null;
			String strTitle = null;
			String strAuthor = null;
			String strPublisher = null;
			String strPublicationDate = null;
			String strType = null;

			@Override
			public void actionPerformed(ActionEvent e) {

				strISBN = ISBN.getText().trim();
				strTitle = Title.getText().trim();
				strAuthor = Authors.getText().trim();
				strPublisher = Publisher.getText().trim();
				strPublicationDate = PublicationDate.getText().trim();
				strType = Type.getText().trim();

				boolean empty = strISBN.equals("") && strTitle.equals("") && strAuthor.equals("")
						&& strPublisher.equals("") && strPublicationDate.equals("") && strType.equals("");

				if (empty) {
					
					JOptionPane.showMessageDialog(null, "查询项输入不能为空！！", "提示", 1);
				
				} else {
					
					Vector<Vector<String>> List = WJDsql.getBookList(strISBN, strTitle, strAuthor, strPublisher,
							strPublicationDate, strType, "ISBN");
					
					if (List.isEmpty()) {
						
						JOptionPane.showMessageDialog(null, "未查询到相关书籍。", "提示", 1);
					
					} else {
						
						@SuppressWarnings("unused")
						ResultFrame resultFrame = new ResultFrame(strISBN, strTitle, strAuthor, strPublisher,
								strPublicationDate, strType);
					
					}
				}

			}
		});

		this.add(ISBNLabel);
		this.add(TitleLabel);
		this.add(AuthorsLabel);
		this.add(PublisherLabel);
		this.add(PublicationDateLabel);
		this.add(TypeLabel);
		this.add(ISBN);
		this.add(Title);
		this.add(Authors);
		this.add(Publisher);
		this.add(PublicationDate);
		this.add(Type);
		this.add(query);

		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);

	}

}
