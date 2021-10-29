package WJDChatRoom.Entity;

import java.io.Serializable;
import java.net.*;
import java.util.*;

// UpdateData类用于存放更新后的Vector和HashMap
public class UpdateData implements Serializable{
	
	private static final long serialVersionUID = 1L;
	
	private Vector<Vector<String>> List;
	private HashMap<String, InetSocketAddress> Map;
	
	public UpdateData(Vector<Vector<String>> list, HashMap<String, InetSocketAddress> Map) {
		this.List = list;
		this.Map = Map;
	}

	public HashMap<String, InetSocketAddress> getMap() {
		return Map;
	}

	public void setMap(HashMap<String, InetSocketAddress> map) {
		Map = map;
	}

	public Vector<Vector<String>> getList() {
		return List;
	}

	public void setList(Vector<Vector<String>> list) {
		List = list;
	}
	
}
