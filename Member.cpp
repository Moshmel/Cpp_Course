#include "Member.h"
#include <vector>
#include <string.h>
using namespace std;
int Member::counter = 0;





Member::~Member()
{
	counter--;

	delete _name;
	_following.clear();
	_followers.clear();

	/*
	Member *temp;
	int num = _users.size();
	bool  ifmatch = true;
	while (ifmatch)
	{

		if(_users[num]->_name==_name)
		{
			temp = _users[num];
			int followingSize = temp->numFollowing();
			while (followingSize > 0)
			{
				Member *tempUser = temp->_following[followingSize];
				temp->unfollow(*tempUser);
				followingSize--;

			}
			int followersSize = temp->numFollowers();
			while (followersSize > 0)
			{
				Member *tempUserFollower = temp->_followers[followersSize];
				tempUserFollower->unfollow(*temp);
				followersSize--;
			}
			_users.erase(_users.begin() + num);
			ifmatch = false;
		}
		num--;
	}
	delete this;
	*/
}

//construture
Member::Member()
{
	_name = NULL;
	counter++;
	
}
Member::Member(char* name)
{
	counter++;
	_name = name;
   	Member::~ Member();
}

int Member::numFollowers(void)
{
	return _followers.size();
}

int Member::numFollowing()
{
	return _following.size();
}


//check if the member already follow him if not he adds him
void Member::follow(Member &user)
{

	for (unsigned int i = 0; i < _following.size(); i++)
	{
		if (_following[i] == &user)return;
	}
	_following.push_back(&user); //this follow new member
	user._followers.push_back(this);
}

//removing the follower and the following  each from theire lists
void Member::unfollow(Member &user)
{
	if (_following.size() > 0 && user._followers.size() > 0)
	{
		for (unsigned int i = 0; i < _following.size(); i++)       //search in the vector for match
		{
			if (&user == _following[i])
			{
				_following.erase(_following.begin() + i);
				for (unsigned int j = 0; j < user._followers.size(); j++)       //search in the vector for match
				{
					if (this == user._followers[j])
					{
						user._followers.erase(user._followers.begin() + j);
						return;
					}
				}
			}
		}
	}
}


