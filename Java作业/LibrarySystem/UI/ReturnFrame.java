package LibrarySystem.UI;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.table.*;

import com.mysql.cj.x.protobuf.MysqlxDatatypes.Array;

import LibrarySystem.sql.WJDsql;

public class ReturnFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	// 窗口宽度
	final int WIDTH = 250;
	// 窗口高度
	final int HEIGHT = 475;

	// 创建标签
	public JLabel Tag = new JLabel("请选择已借书籍:");

	// 已借书籍列表的列标题
	public Vector<String> Title = new Vector<String>();
	// 已借书籍列表的数据
	public Vector<Vector<String>> Data = new Vector<Vector<String>>();

	// 创建已借书籍列表
	public MyTableModel Model = null;
	public JTable List = null;

	JScrollPane ListScroll = new JScrollPane();

	public ReturnFrame(Vector<Vector<String>> RecordList, Integer ReaderID) {

		// 标题
		setTitle("还书窗口");
		// 大小
		setSize(WIDTH, HEIGHT);
		// 不可缩放
		setResizable(false);
		// 设置布局:不适用默认布局，完全自定义
		setLayout(null);

		// Tag
		Tag.setBounds(20, 20, 160, 20);
		Tag.setFont(new Font("华文楷体", Font.PLAIN, 18));
		Tag.setBorder(null);
		this.add(Tag);

		// List初始化以及去掉表头和格式设置
		// 构建MyTableModel初始化List
		Title.add("");
		Data = RecordList;
		Model = new MyTableModel();
		Model.setDataVector(Data, Title);
		List = new JTable(Model);

		DefaultTableCellRenderer renderer = new DefaultTableCellRenderer();
		renderer.setPreferredSize(new Dimension(0, 0));
		List.getTableHeader().setDefaultRenderer(renderer);
		List.setFont(new Font("华文楷体", Font.PLAIN, 18));
		List.setBorder(null);
		List.setRowHeight(25);
		List.updateUI();

		// List滚动窗
		ListScroll.setViewportView(List);
		ListScroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		ListScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
		ListScroll.setBounds(20, 52, 205, 370);

		// 添加用户列表的滚动窗
		this.add(ListScroll);

		// 用户列表窗口显示设置
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		// 获取本机屏幕横向纵向分辨率
		int w = Toolkit.getDefaultToolkit().getScreenSize().width;
		int h = Toolkit.getDefaultToolkit().getScreenSize().height;

		setLocation((w - WIDTH) / 2 + 400, (h - HEIGHT) / 2 - 43);

		setVisible(true);

		// 点击列表事件
		List.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {

				String Title = (String) List.getValueAt(List.getSelectedRow(), 0);
				int result = JOptionPane.showConfirmDialog(null, "是否归还《" + Title + "》？", "提示", JOptionPane.YES_NO_OPTION);

				if (result == JOptionPane.YES_OPTION) {
					
					WJDsql.deleteRecord(Title, ReaderID);
					JOptionPane.showMessageDialog(null, Title + " 归还成功！", "提示", 1);
					
					// 更新列表
					Data.remove(new Vector<String>(Arrays.asList(Title)));
					Model.setDataVector(Data, ReturnFrame.this.Title);
				}

				List.getSelectionModel().clearSelection();
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
