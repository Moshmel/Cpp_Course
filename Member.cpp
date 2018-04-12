#include "Member.h"
#include <vector>
#include <string.h>
using namespace std;
int Member::counter = 0;





Member::~Member()
{
	counter--;
	
	for (unsigned int i = 0; i < this->_following.size(); i++)
	{
		Member *temp = this->_following[i];
		for (int j = 0; j < temp->_followers.size(); j++)
			if (temp->_followers[j] == this)temp->_followers.erase(temp->_followers.begin() + j);
	}
	for (unsigned int i = 0; i < this->_followers.size(); i++)
	{
		Member *temp = this->_followers[i];
		for (int j = 0; j < temp->_following.size(); j++)
			if (temp->_following[j] == this)temp->_following.erase(temp->_following.begin() + j);
	}
	for (unsigned int i = 0; i < _users.size(); i++)
	{
		if (_users[i] == this)_users.erase(_users.begin() + i);
		break;
	}


	
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
	if (&user != this)
	{
		for (unsigned int i = 0; i < _following.size(); i++)
		{
			if (_following[i] == &user)return;
		}
		_following.push_back(&user); //this follow new member
		user._followers.push_back(this);
	}
}

//removing the follower and the following  each from theire lists
void Member::unfollow(Member &user)
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



