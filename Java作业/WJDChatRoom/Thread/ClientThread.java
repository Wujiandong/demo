package WJDChatRoom.Thread;

import java.io.*;
import java.net.*;
import java.util.Vector;

import WJDChatRoom.Entity.UpdateData;
import WJDChatRoom.Main.Client;
import WJDChatRoom.UI.*;

/***********************************
 * 客户端线程ClientThread: 
 * 1、获取所有好友的名单Vector
 * 2、获取HashMap，得到所有好友的IP地址
 * 3、更新显示在线用户列表
 * 
 ***********************************/
public class ClientThread implements Runnable {

	// 客户端
	private Client client;
	// 用户列表界面框架
	private OnlineListFrame onlineListFrame;

	public ClientThread(Client client, OnlineListFrame onlineListFrame) {
		this.client = client;
		this.onlineListFrame = onlineListFrame;
	}

	@Override
	public void run() {

		boolean isLine = true;
		try {

			while (isLine) {

				ObjectInputStream in = new ObjectInputStream(client.clientSocket.getInputStream());
				Object Message = in.readObject();

				// 通过收到的信息，更新客户端的列表信息
				if (Message instanceof UpdateData) {

					//更新客户端信息
					UpdateData NewData = (UpdateData) Message;
					onlineListFrame.client.Map = NewData.getMap();
					onlineListFrame.Data = NewData.getList();
					
					//在列表中去掉自己名字
					Vector<String> str = new Vector<String>();
					str.add(client.userEntity.getUserID());
					onlineListFrame.Data.remove(str);
					onlineListFrame.Model.setDataVector(onlineListFrame.Data, onlineListFrame.Title);

				}

			}

		  //当用户点击×号后，用户下线，或者服务器关闭，Socket关闭，抛出SocketException异常
		} catch (SocketException e) {
			
			//退出循环，进程结束
			isLine = false;
			System.out.println(client.userEntity.getUserID() + "客户端已关闭或服务器已关闭...");
			e.printStackTrace();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
