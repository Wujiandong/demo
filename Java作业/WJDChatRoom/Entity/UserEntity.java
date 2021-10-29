package WJDChatRoom.Entity;

import java.io.Serializable;

public class UserEntity implements Serializable{

	private static final long serialVersionUID = 1L;
	
	private String UserID;
	private String UserPwd;
	
	public String getUserID() {
		return UserID;
	}
	
	public void setUserID(String userID) {
		this.UserID = userID;
	}
	
	public String getUserPwd() {
		return UserPwd;
	}
	
	public void setUserPwd(String userPwd) {
		this.UserPwd = userPwd;
	}
	
	@Override
	public String toString() {
		return "UserEntity [UserID=" + UserID + ", UserPwd=" + UserPwd + "]";
	}
	
}
