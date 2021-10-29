package WJDChatRoom.Entity;

import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;

// Message类是聊天发送的消息载体
public class Message implements Serializable{

	private static final long serialVersionUID = 1L;
	
	//用户信息
	private UserEntity user = null;
	//消息发送时间
	private String Time = null;
	//消息内容
	private String Content = null;
	
	
	public Message(UserEntity user, String Content) {
		
		this.user = user;
		this.Content = Content;
		
		//设置时间显示样式
		LocalDateTime localDateTime = LocalDateTime.now();
        this.Time = localDateTime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm"));
	
	}

	public UserEntity getUser() {
		return user;
	}

	public void setUser(UserEntity user) {
		this.user = user;
	}

	public String getTime() {
		return Time;
	}
	
	public void setTime(String time) {
		Time = time;
	}

	public String getContent() {
		return Content;
	}

	public void setContent(String content) {
		Content = content;
	}

	public String ShowMessage(){
		
		String message = new String(user.getUserID() + "    " + Time + "\n" + Content + "\n");
		return message;
	}

	
}
