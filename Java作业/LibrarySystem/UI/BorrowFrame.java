package LibrarySystem.UI;

import java.awt.*;
import java.awt.event.*;
import java.util.Vector;

import javax.swing.*;

import LibrarySystem.sql.WJDsql;

public class BorrowFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 窗口宽度
	final int WIDTH = 300;
	// 窗口高度
	final int HEIGHT = 200;

	// 创建请输入书名标签
	public JLabel Tag = new JLabel("请输入书名：");
	// 创建书名输入文本框
	public JTextField Title = new JTextField();
	// 创建查询按钮
	public JButton Query = new JButton("查询");

	public BorrowFrame(Integer ReaderID) {
		// 标题
		setTitle("借书窗口");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		Tag.setBounds(40, 40, 100, 30);
		Title.setBounds(133, 40, 125, 30);
		Query.setBounds(115, 102, 70, 30);

		Tag.setFont(new Font("宋体", Font.PLAIN, 14));
		Title.setFont(new Font("宋体", Font.PLAIN, 14));
		Query.setFont(new Font("宋体", Font.PLAIN, 14));

		this.add(Tag);
		this.add(Title);
		this.add(Query);

		Query.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				String ReturnDate = WJDsql.checkBorrowed(Title.getText());

				if (ReturnDate == null) {

					if (WJDsql.checkBook(Title.getText()) == null) {

						JOptionPane.showMessageDialog(null, "不存在此书籍。", "提示", 1);

					} else {

						if (WJDsql.checkLimits(ReaderID) != 0) {

							
							int result = JOptionPane.showConfirmDialog(null, "是否借阅《" + Title.getText() + "》？", "提示", JOptionPane.YES_NO_OPTION);

							if (result == JOptionPane.YES_OPTION) {
								
								// 插入借阅记录并更新用户限借数目
								WJDsql.insertRecord(Title.getText(), ReaderID);
								WJDsql.updateLimits(ReaderID, 1);
								
								JOptionPane.showMessageDialog(null, "借阅成功！您此次借阅书名为：" + Title.getText(), "提示", 1);
								
							}

						} else {

							JOptionPane.showMessageDialog(null, "您的借阅数量已满，无法借阅。" + ReturnDate, "提示", 1);
						}
					}

				} else {

					JOptionPane.showMessageDialog(null, "该书已被借出，归还日期为：" + ReturnDate, "提示", 1);

				}

			}
		});

		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);
	}

}
