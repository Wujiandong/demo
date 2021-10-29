package WJDChatRoom.UI;

import java.awt.*;
import java.awt.event.*;
import java.net.*;
import javax.swing.*;

import WJDChatRoom.Entity.UserEntity;
import WJDChatRoom.Main.Client;
import WJDChatRoom.Thread.*;

public class LoginFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 创建登录窗口客户端Socket
	public Socket socket = null;
	// 创建用户信息对象
	public UserEntity userEntity = null;

	// 窗口宽度
	final int WIDTH = 300;
	// 窗口高度
	final int HEIGHT = 250;

	// 创建用户名文本框
	public JTextField IDText = new JTextField("用户名");
	// 创建密码文本框
	public JTextField PwdText = new JTextField("密码");
	// 创建用户名输入文本框
	public JTextField UserID = new JTextField();
	// 创建密码输入文本框
	public JPasswordField UserPwd = new JPasswordField();

	// 创建登录按钮
	public JButton Login = new JButton("登录");
	// 创建退出按钮
	public JButton Exit = new JButton("退出");

	public LoginFrame() {

		// 标题
		setTitle("登录窗口");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		// 设置文本框大小和位置
		IDText.setBounds(40, 42, 65, 25);
		PwdText.setBounds(40, 92, 65, 25);
		UserID.setBounds(130, 42, 120, 25);
		UserPwd.setBounds(130, 92, 120, 25);

		// 按钮大小和位置设置和添加
		Login.setBounds(170, 150, 60, 30);
		Exit.setBounds(70, 150, 60, 30);
		this.add(Login);
		this.add(Exit);

		// 文本框设置和添加
		IDText.setEditable(false);
		IDText.setBorder(null);
		IDText.setFont(new Font("幼圆", Font.BOLD, 14));
		IDText.setHorizontalAlignment(SwingConstants.CENTER);

		PwdText.setEditable(false);
		PwdText.setBorder(null);
		PwdText.setFont(new Font("幼圆", Font.BOLD, 14));
		PwdText.setHorizontalAlignment(SwingConstants.CENTER);

		UserID.setFont(new Font("宋体", Font.PLAIN, 14));

		this.add(IDText);
		this.add(PwdText);
		this.add(UserID);
		this.add(UserPwd);

		// 登录按钮事件
		Login.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				try {

					// 判断用户名和密码是否为空
					StringBuffer sb = new StringBuffer();

					for (int i = 0; i < UserPwd.getPassword().length; i++) {
						sb.append(UserPwd.getPassword()[i]);
					}

					String ID = new String(UserID.getText());
					String Pwd = new String(sb.toString());

					// 无输入的提示
					if ("".equals(ID.trim()) || "".equals(Pwd.trim())) {

						JOptionPane.showMessageDialog(null, "用户名或密码不能为空！！", "提示", 1);

					} else {

						// 将输入的用户名和密码记录到对象中
						UserEntity userEntity = new UserEntity();
						userEntity.setUserID(ID);
						userEntity.setUserPwd(Pwd);

						// 启动客户端，将用户信息发送至服务器
						Client client = new Client(userEntity);
						client.start();

						// 通过客户端登录状态，选择 隐藏窗口、打开在线列表 或 弹出提示
						if (client.loginState == 1) {

							closeFrame();
							OnlineListFrame onlineListFrame = new OnlineListFrame(client, client.userEntity);
							new Thread(new ClientThread(client, onlineListFrame)).start();
							new Thread(new MessageThread(client, onlineListFrame)).start();

						} else if (client.loginState == 2) {
							JOptionPane.showMessageDialog(null, "该用户已在线！", "提示", 1);
						} else {
							JOptionPane.showMessageDialog(null, "服务器未开启！", "提示", 1);
						}
					}
				} catch (Exception ex) {
					ex.printStackTrace();
				} finally {
					// 用户名输入框清除
					UserID.setText("");
					// 密码输入框清除
					UserPwd.setText("");
				}
			}
		});

		// 退出按钮事件
		Exit.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setLocationRelativeTo(null);

		setVisible(true);

	}

	// 关闭登录窗口
	private void closeFrame() {

		this.dispose();

	}

}
