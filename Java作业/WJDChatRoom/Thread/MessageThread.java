package WJDChatRoom.Thread;

import java.io.*;
import java.net.*;

import WJDChatRoom.Entity.Message;
import WJDChatRoom.Main.Client;
import WJDChatRoom.UI.ChatFrame;
import WJDChatRoom.UI.OnlineListFrame;

/******************************************
 *  消息线程MessageThread:
 *  1、 接收其他用户发来的DatagramPacket
 *  2、 根据窗口打开状态，选择是否初始化聊天窗口
 *  3、 将收到的DatagramPacket转化成Message信息
 *     并在聊天窗口上显示
 *  
 ******************************************/
public class MessageThread implements Runnable {

	// 客户端
	private Client client = null;
	// 用户列表界面框架
	private OnlineListFrame onlineListFrame = null;
	// 客户端数据报Socket
	private DatagramSocket datagramSocket = null;
	// 消息Buffer
	private byte[] inBuffer = null;

	public MessageThread(Client client, OnlineListFrame onlineListFrame) {

		try {
			
			this.client = client;
			this.onlineListFrame = onlineListFrame;
			this.datagramSocket = new DatagramSocket(client.clientSocket.getLocalPort(),
					client.clientSocket.getLocalAddress());
			this.inBuffer = new byte[1024];
		
		} catch (SocketException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void run() {

		System.out.println(client.userEntity.getUserID() + "的消息线程已开启！");

		try {
			
			while (true) {
				
				DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
				
				System.out.println("等待接收消息...");
				datagramSocket.receive(inPacket);
				System.out.println("收到消息了！");
				
				Message message = (Message) ByteToObject(inPacket.getData());

				String Name = message.getUser().getUserID();

				// 如果未打开过该好友的聊天窗口则初始化聊天窗口
				if (!onlineListFrame.WindowOpened.containsKey(Name)) {

					ChatFrame chatFrame = new ChatFrame(client.userEntity, client.Map.get(Name));
					chatFrame.setTitle(client.userEntity.getUserID() + "与" + Name + "的聊天窗口");
					onlineListFrame.WindowOpened.put(Name, chatFrame);
					
				// 如果已经打开过了，则将聊天窗口显示出来
				} else {
					
					onlineListFrame.WindowOpened.get(Name).setVisible(true);
				}

				// 将消息显示在聊天窗口上
				ChatFrame chatFrame = onlineListFrame.WindowOpened.get(Name);
				chatFrame.MessageArea.append(message.ShowMessage());
				
				// 设置光标到底部以显示最新消息
				chatFrame.MessageArea.setCaretPosition(chatFrame.MessageArea.getText().length());
				
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	
	// byte[]转换成对象
	public static Object ByteToObject(byte[] bytes) {

		Object obj = null;

		try {
			// bytearray to object
			ByteArrayInputStream bi = new ByteArrayInputStream(bytes);
			ObjectInputStream oi = new ObjectInputStream(bi);

			obj = oi.readObject();
			bi.close();
			oi.close();
		} catch (Exception e) {
			System.out.println("Translation" + e.getMessage());
			e.printStackTrace();
		}
		return obj;
	}

}

