#include <map>
#include <iostream>
#include <vector>
using namespace std;
class Member
{
	
	char* _name;
	vector<Member*> _following;
	vector<Member*> _followers;
	vector<Member*> _users;
	static int counter;



public:
//	~Member();
	
	Member();
	Member(char* name);
	void follow(Member &user);
	void unfollow(Member &user);
	int	numFollowers();
	int	numFollowing();

	static int count()//member count 
	{
		return Member::counter;
	}

};

