#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
private:
	int lists_size;
	list<pair<int,int>> lists;
	std::unordered_map<int,list<pair<int,int>>::iterator> umap;
public:
	LRUCache(int capacity)
	{
		lists_size = capacity;	
	}

	int get(int key)
	{
		auto it = umap.find(key);
		if(it == umap.end())
			return -1;
		
		auto it_node = umap[key];
		lists.splice(lists.begin(),lists,it_node);
		return it_node->second;
	}

	void put(int key, int value)
	{
		auto it = umap.find(key);
		if(it != umap.end())
		{
			auto it_node = umap[key];
			it_node->second = value;
			lists.splice(lists.begin(),lists,it_node);
		}
		lists.emplace_front(key,value);
		umap[key] = lists.begin();
		if(umap.size() > lists_size)
		{
			auto it_back = lists.back();
			umap.erase(it_back.first);
			lists.pop_back();
		}
	}
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
		for(int  i = 0; i < nums.size(); i++)
			umap[nums[i]]++;
		for(auto it = umap.begin(); it != umap.end(); it++)
		{
			if(it->second == 1)
				return it->first;
		}
		return -1;
    }
};
int main()
{
}