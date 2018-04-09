#include "Member.h"
#include <vector>
using namespace std;
int Member::counter = 0;

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

	for (int i = 0; i < _following.size(); i++)
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
		for (int i = 0; i < _following.size(); i++)       //search in the vector for match
		{
			if (&user == _following[i])
			{
				_following.erase(_following.begin() + i);
				for (int j = 0; j < user._followers.size(); j++)       //search in the vector for match
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