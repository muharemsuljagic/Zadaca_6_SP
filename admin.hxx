#ifndef _ADMIN_HXX_
#define _ADMIN_HXX_

#include<iostream>

class Admin
{
	private:	
	std::string _username;
	std::string _pw;
	
	public:
	Admin():_username("grupa"),_pw("grupa"){}
	
	const std::string getName() { return _username;}
	
	bool CheckAdmin(const std::string&,const std::string&);
};

bool Admin::CheckAdmin(const std::string& username,const std::string& pw)
{
		if((_username==username) && (_pw==pw))
			return true;
		else return false;
}



#endif
