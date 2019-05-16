package com.cdac.springmvcwebapp.dto;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "user")
public class User {
	@Id
	@Column(name = "user_id")
	@GeneratedValue
	private int userId;
	@Column(name = "user_name")
	private String userName;
	@Column(name = "user_pass")
	private String userPass;
	@Column(name = "user_role")
	private String userRole;
	public User() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	
	
	public User(int userId) {
		super();
		this.userId = userId;
	}



	public User(String userName, String userPass, String userRole) {
		super();
		this.userName = userName;
		this.userPass = userPass;
		this.userRole = userRole;
	}

	public User(int userId, String userName, String userPass, String userRole) {
		super();
		this.userId = userId;
		this.userName = userName;
		this.userPass = userPass;
		this.userRole = userRole;
	}



	public int getUserId() {
		return userId;
	}
	public void setUserId(int userId) {
		this.userId = userId;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getUserPass() {
		return userPass;
	}
	public void setUserPass(String userPass) {
		this.userPass = userPass;
	}
	public String getUserRole() {
		return userRole;
	}
	public void setUserRole(String userRole) {
		this.userRole = userRole;
	}
	@Override
	public String toString() {
		return userId + " " + userName + " " + userPass + " " + userRole;
	}
	
	
}
