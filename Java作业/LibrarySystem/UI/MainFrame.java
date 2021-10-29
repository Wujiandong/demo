package LibrarySystem.UI;

import javax.swing.*;

import LibrarySystem.sql.WJDsql;

import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("unused")
public class MainFrame extends JFrame{

	private static final long serialVersionUID = 1L;
	
	// 窗口宽度
	final int WIDTH = 300;
	// 窗口高度
	final int HEIGHT = 250;

	// 创建标题
	public JLabel Title = new JLabel("图书管理界面");
	
	// 用户ID
	public Integer ReaderID = null;
	
	// 创建查询按钮
	public JButton Query = new JButton("查询");
	// 创建借书按钮
	public JButton Borrow = new JButton("借书");
	// 创建还书按钮
	public JButton Return = new JButton("还书");
	
	public MainFrame(Integer ReaderID) {
		
		this.ReaderID = ReaderID;
		
		// 标题
		setTitle("图书管理窗口");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);
		
		Title.setBounds(55, 20, 200, 70);
		Query.setBounds(25, 120, 70, 40);
		Borrow.setBounds(113, 120, 70, 40);
		Return.setBounds(200, 120, 70, 40);
		
		Title.setFont(new Font("宋体", Font.PLAIN, 30));
		Query.setFont(new Font("幼圆", Font.PLAIN, 17));
		Borrow.setFont(new Font("幼圆", Font.PLAIN, 17));
		Return.setFont(new Font("幼圆", Font.PLAIN, 17));
		
		Query.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				QueryFrame queryFrame = new QueryFrame();
				
			}
		});
		
		Borrow.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				BorrowFrame borrowFrame = new BorrowFrame(ReaderID);
				
			}
		});
		
		Return.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {

				ReturnFrame returnFrame = new ReturnFrame(WJDsql.getRecordList(ReaderID), ReaderID);
				
			}
		});
		
		this.add(Title);
		this.add(Query);
		this.add(Borrow);
		this.add(Return);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);
					
	}
	
	public static void main(String[] args) {
		MainFrame temp = new MainFrame(221900128);
	}

}
