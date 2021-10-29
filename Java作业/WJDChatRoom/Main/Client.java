package WJDChatRoom.Main;

import java.io.*;
import java.net.*;
import java.util.*;

import WJDChatRoom.Entity.*;
import WJDChatRoom.UI.LoginFrame;

public class Client {

	// 建立客户端Socket
	public Socket clientSocket;
	// 建立用户信息对象
	public UserEntity userEntity;
	// 建立 <String, InetSocketAddress> HashMap
	public HashMap<String, InetSocketAddress> Map = new HashMap<String, InetSocketAddress>();
	// 用户登录状态		1为成功登陆，2为用户已上线，3为服务器未开启
	public int loginState;

	//开启客户端，出现登录界面
	public static void main(String[] args) {

		@SuppressWarnings("unused")
		LoginFrame login = new LoginFrame();

	}
	
	public Client(UserEntity userEntity) {

		try {
			clientSocket = new Socket(InetAddress.getLocalHost(), 9999);
			this.userEntity = userEntity;
			this.loginState = 3;

		} catch (IOException e) {
			
			System.out.println("服务器未开启，客户端连接失败...");
			
		}
	}

	public void start() {

		ObjectOutputStream out;
		ObjectInputStream in;

		try {

			out = new ObjectOutputStream(clientSocket.getOutputStream());
			in = new ObjectInputStream(clientSocket.getInputStream());

			// 向服务器发送用户实体
			out.writeObject(userEntity);
			out.flush();

			// 更新客户端登录状态
			loginState = (int) in.readObject();

		} catch (Exception e) {
			
			System.out.println("");
			
		}
	}

	//客户端UDP消息发送
	public static void SendMessage(InetSocketAddress Guest, Message message) {

		try {

			// 连接好友的DatagramSocket
			DatagramSocket datagramSocket = new DatagramSocket();
			datagramSocket.connect(Guest);
			
			//将Message消息类转化成byte数组
			byte[] bytes = ObjectToByte(message);
			
			//将转化后的消息发送给好友
			DatagramPacket outPacket = new DatagramPacket(bytes, bytes.length);
			datagramSocket.send(outPacket);
			System.out.println("已发送消息给" + datagramSocket.getInetAddress() + "  " + datagramSocket.getPort());
			
			datagramSocket.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// 对象转换成byte[]
	public static byte[] ObjectToByte(Object obj) {

		byte[] bytes = null;

		try {
			// object to bytearray
			ByteArrayOutputStream bo = new ByteArrayOutputStream();
			ObjectOutputStream oo = new ObjectOutputStream(bo);
			oo.writeObject(obj);

			bytes = bo.toByteArray();

			bo.close();
			oo.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return bytes;
	}

}
