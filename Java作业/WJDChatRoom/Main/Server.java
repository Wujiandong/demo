package WJDChatRoom.Main;

import java.io.*;
import java.net.*;
import java.util.*;

import WJDChatRoom.Thread.ServerThread;

public class Server {

	// 建立服务器ServerSocket
	private ServerSocket serverSocket;
	// 静态ArrayList存储所有用户名
	public static ArrayList<String> UserNameArray = new ArrayList<String>();
	// 静态HashMap存储所有用户名与Socket组成的键值对
	public static HashMap<String, Socket> Str_Soct_Map = new HashMap<String, Socket>();
	// 静态HashMap存储所有用户名与InetSocketAddress组成的键值对
	public static HashMap<String, InetSocketAddress> Str_Add_Map = new HashMap<String, InetSocketAddress>();

	public static void main(String[] args) throws IOException {

		Server server = new Server();
		server.start();

	}

	public Server() {
		try {
			serverSocket = new ServerSocket(9999,1000,InetAddress.getLocalHost());
			System.out.println("服务器启动成功.." + serverSocket.getInetAddress());
		} catch (IOException e) {
			System.out.println("服务器启动失败。");
		}
	}

	public void start() {
		try {
			while (true) {
				// 接收客户端Socket
				Socket clientSocket = serverSocket.accept();

				System.out.println("已接收到客户端Socket：" + clientSocket.getInetAddress() + "  " + clientSocket.getPort());

				// 建立新的服务器线程, 向该线程提供客户端clientSocket
				new Thread(new ServerThread(clientSocket)).start();
			}
		} catch (IOException e) {
			System.out.println("Server.start() is Error");
		}
	}
}
