package WJDChatRoom.UI;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;

import WJDChatRoom.Entity.UserEntity;
import WJDChatRoom.Main.Client;

@SuppressWarnings("unused")
public class OnlineListFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 客户端Socket
	public Client client;
	// 存放用户信息
	public UserEntity userEntity;
	// WindowOpened用于记录已打开的好友聊天窗口
	public HashMap<String, ChatFrame> WindowOpened;
	
	// 窗口宽度
	final int WIDTH = 250;
	// 窗口高度
	final int HEIGHT = 550;
	// 创建用户信息文本框
	public JTextField UserName = new JTextField("");
	// 创建好友列表标题栏
	public JLabel FriendTitle = new JLabel("当前在线好友:");

	// 当前在线列表的列标题
	public Vector<String> Title = new Vector<String>();
	// 当前在线列表的数据
	public Vector<Vector<String>> Data = new Vector<Vector<String>>();

	// 创建在线用户列表, 
	public MyTableModel Model = null;
	public JTable UserList = null;

	JScrollPane UserListScroll = new JScrollPane();

	public OnlineListFrame(Client client, UserEntity userEntity) {

		this.client = client;
		this.userEntity = userEntity;
		this.WindowOpened = new HashMap<String, ChatFrame>();

		// 标题
		setTitle("");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		// 用户名显示框
		UserName.setText(userEntity.getUserID());
		UserName.setBounds(20, 20, 205, 70);
		UserName.setFont(new Font("华文楷体", Font.PLAIN, 40));
		UserName.setEditable(false);
		UserName.setBorder(null);
		UserName.setHorizontalAlignment(SwingConstants.CENTER);
		this.add(UserName);

		// Tag
		FriendTitle.setBounds(20, 105, 160, 20);
		FriendTitle.setFont(new Font("华文楷体", Font.PLAIN, 18));
		FriendTitle.setBorder(null);
		this.add(FriendTitle);

		// UserList初始化以及去掉表头和格式设置
		// 构建MyTableModel初始化UserList
		Title.add("");
		Data.add(Title);
		Model = new MyTableModel();
		Model.setDataVector(Data, Title);
		UserList = new JTable(Model);

		DefaultTableCellRenderer renderer = new DefaultTableCellRenderer();
		renderer.setPreferredSize(new Dimension(0, 0));
		UserList.getTableHeader().setDefaultRenderer(renderer);
		UserList.setFont(new Font("华文楷体", Font.PLAIN, 18));
		UserList.setBorder(null);
		UserList.setRowHeight(25);
		UserList.updateUI();

		// UserList滚动窗
		UserListScroll.setViewportView(UserList);
		UserListScroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		UserListScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		UserListScroll.setBounds(20, 130, 205, 370);

		// 添加用户列表的滚动窗
		this.add(UserListScroll);

		// 用户列表窗口显示设置
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// 获取本机屏幕横向纵向分辨率
		int w = Toolkit.getDefaultToolkit().getScreenSize().width;
		int h = Toolkit.getDefaultToolkit().getScreenSize().height;

		setLocation((w - WIDTH) / 2 + 400, (h - HEIGHT) / 2 - 43);

		setVisible(true);

		// 点击好友列表事件
		UserList.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {

				String Name = (String) UserList.getValueAt(UserList.getSelectedRow(), 0);
				InetSocketAddress Guest = client.Map.get(Name);

				if (Name != null) {

					// 确保对同一个好友的多次点击只打开一个窗口
					// 如果 未打开过该好友的聊天窗口 或 该好友的聊天窗口已关闭 则打开窗口
					if (!WindowOpened.containsKey(Name)) {

						ChatFrame chatFrame = new ChatFrame(userEntity, Guest);
						chatFrame.setTitle(userEntity.getUserID() + "与" + Name + "的聊天窗口");
						WindowOpened.put(Name, chatFrame);

					} else {

						WindowOpened.get(Name).setVisible(true);

					}
				}
				UserList.getSelectionModel().clearSelection();
			}
		});

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
