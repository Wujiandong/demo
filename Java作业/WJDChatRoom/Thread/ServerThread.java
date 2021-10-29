package WJDChatRoom.Thread;

import java.io.*;
import java.net.*;
import java.util.Vector;

import WJDChatRoom.Entity.*;
import WJDChatRoom.Main.Server;



/************************************************
 * 服务器线程ServerThread: 
 * 1、接收客户端发来的登录信息并回传确认信息 
 * 2、登陆成功后，向所有在线用户发送更新后的： 
 * (1) 在线用户姓名Vector 
 * (2) 用户名与InetSocketAddress组成的键值对HashMap
 * 
 ************************************************/
public class ServerThread implements Runnable {

	// 获取的客户端Socket
	Socket clientSocket = null;

	// 获取的用户名
	String Name = null;

	public ServerThread(Socket clientSocket) {
		this.clientSocket = clientSocket;
	}

	@Override
	public void run() {

		ObjectInputStream in = null;

		ObjectOutputStream out = null;

		boolean isLine = true;

		try {

			while (isLine) {

				in = new ObjectInputStream(clientSocket.getInputStream());

				out = new ObjectOutputStream(clientSocket.getOutputStream());

				System.out.println("准备聊天...");

				Object object = in.readObject();

				if (object instanceof UserEntity) {
					// 获取登录窗口传来的用户名和密码
					UserEntity userEntity = (UserEntity) object;

					System.out.println(userEntity);
					Name = userEntity.getUserID();
					// String Pwd = userEntity.getUserPwd();

					if (Server.Str_Soct_Map.containsKey(Name)) {

						// 将用户存在信息回传至登录窗口
						int Check = 2;
						out.writeObject(Check);
						out.flush();

					} else {

						// 将当前客户端用户名存入ArrayList
						Server.UserNameArray.add(Name);
						// 将当前用户名和Socket对存入HashMap
						Server.Str_Soct_Map.put(Name, this.clientSocket);
						// 将当前用户名和InetSocketAddress对存入HashMap
						InetSocketAddress ISA = new InetSocketAddress(this.clientSocket.getInetAddress(),
								this.clientSocket.getPort());
						Server.Str_Add_Map.put(Name, ISA);

						// 将用户存在信息回传至登录窗口
						int Check = 1;
						out.writeObject(Check);
						out.flush();

						// 更新所有用户的OnlineList
						UpdateOnlineList();

					}
				}

			}
			// 对某一用户关闭窗口时的异常处理
		} catch (SocketException e) {

			// 在服务器的所有记录表中去掉该用户的信息，同时更新所有好友的在线列表，
			Server.UserNameArray.remove(Name);
			Server.Str_Soct_Map.remove(Name);
			Server.Str_Add_Map.remove(Name);
			UpdateOnlineList();
			System.out.println("用户" + Name + "下线了...");
			isLine = false;

		} catch (IOException e) {
			System.out.println("run() is IOError");
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			System.out.println("run() is ClassNotFoundError");
			e.printStackTrace();
		}
	}

	// 向所有用户发送更新后的Vector、HashMap
	public void UpdateOnlineList() {

		ObjectOutputStream out;

		Vector<Vector<String>> List = new Vector<Vector<String>>();

		for (String str : Server.UserNameArray) {
			Vector<String> Temp = new Vector<String>();
			Temp.add(str);
			List.add(Temp);
		}

		UpdateData data = new UpdateData(List, Server.Str_Add_Map);

		for (String Name : Server.UserNameArray) {

			// 获取广播收听者的输出流
			try {
				out = new ObjectOutputStream(Server.Str_Soct_Map.get(Name).getOutputStream());
				out.writeObject(data);
				out.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}
	}
}

