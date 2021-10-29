package WJDChatRoom.UI;

import javax.swing.*;

import WJDChatRoom.Entity.Message;
import WJDChatRoom.Entity.UserEntity;
import WJDChatRoom.Main.Client;

import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.time.format.DateTimeFormatter;

@SuppressWarnings("unused")
public class ChatFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	// 用户信息
	private UserEntity user = null;
	// 好友InetSocketAddress
	private InetSocketAddress Guest = null;

	// 窗口宽度
	final int WIDTH = 550;
	// 窗口高度
	final int HEIGHT = 635;

	// 创建发送按钮
	JButton Send = new JButton("发送");
	// 创建清除按钮
	JButton Clear = new JButton("清屏");

	// 创建聊天消息框
	public JTextArea MessageArea = new JTextArea();

	// 创建文本输入框, 参数分别为行数和列数
	JTextArea TextIN = new JTextArea();

	// 创建聊天消息框的滚动窗
	public JScrollPane MessageScroll = new JScrollPane(MessageArea);

	// 创建文本输入框的滚动窗
	JScrollPane TextINScroll = new JScrollPane(TextIN);

	public ChatFrame(UserEntity user, InetSocketAddress Guest) {

		this.user = user;
		this.Guest = Guest;

		// 标题
		setTitle("聊天客户端");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		// 设置按钮大小和位置
		Clear.setBounds(20, 550, 80, 40);
		Send.setBounds(440, 550, 80, 40);

		// 设置按钮文本的字体
		Clear.setFont(new Font("宋体", Font.BOLD, 18));
		Send.setFont(new Font("宋体", Font.BOLD, 18));

		// 添加按钮
		this.add(Clear);
		this.add(Send);

		// 聊天消息框自动换行
		MessageArea.setLineWrap(true);
		// 聊天框不可编辑，只用来显示
		MessageArea.setEditable(false);
		// 设置聊天框字体
		MessageArea.setFont(new Font("华文楷体", Font.PLAIN, 18));

		// 设置滚动窗的水平滚动条属性:不出现
		MessageScroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		// 设置滚动窗的垂直滚动条属性:需要时自动出现
		MessageScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		// 设置滚动窗大小和位置
		MessageScroll.setBounds(20, 20, 500, 350);
		// 添加聊天窗口的滚动窗
		this.add(MessageScroll);

		// 设置文本输入框可编辑
		TextIN.setEditable(true);
		// 设置文本输入框自动换行
		TextIN.setLineWrap(true);
		// 设置文本输入框字体
		TextIN.setFont(new Font("华文楷体", Font.PLAIN, 20));

		// 设置滚动窗的水平滚动条属性:不出现
		TextINScroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		// 设置滚动窗的垂直滚动条属性:需要时自动出现
		TextINScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		// 设置滚动窗大小和位置
		TextINScroll.setBounds(20, 390, 500, 150);
		// 添加文本输入窗口的滚动窗
		this.add(TextINScroll);

		// 添加发送按钮的响应事件
		Send.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {

				if (! "".equals(TextIN.getText())) {
					
					Message message = new Message(user, TextIN.getText());
					Client.SendMessage(Guest, message);
					MessageArea.append(message.ShowMessage());
					TextIN.setText("");
				
				} else {
					
					JOptionPane.showMessageDialog(null, "发送内容不能为空！！", "提示", 1);
				
				}

			}
		});

		// 添加清屏按钮的响应事件
		Clear.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {
				// 聊天框清屏
				MessageArea.setText("");
			}
		});

		// 按下回车发送
		TextIN.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                if (e.getKeyChar() == KeyEvent.VK_ENTER) {
                	if (! TextIN.getText().equals("\n")) {
    					
    					Message message = new Message(user, TextIN.getText().replace("\n", ""));
    					Client.SendMessage(Guest, message);
    					MessageArea.append(message.ShowMessage());
    					TextIN.setText("");
    				
    				} else {
    					
    					TextIN.setText("");
    					JOptionPane.showMessageDialog(null, "发送内容不能为空！！", "提示", 1);
    				
    				}
                }
            }
        });
		
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);

	}

}
