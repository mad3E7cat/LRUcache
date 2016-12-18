#pragma once
#include "lru_cache.h" 
using namespace std;

LruCache::LruCache(int _size)
{
	size = _size;
	used = 0;
	for(auto it_lst = list.begin(); it_lst != list.end(); it_lst++)
	{
		addressMap.insert(*it_lst);
	}
	for(int i = 0; i < size; i++)
	{
		list.push_back(pair<string, int>("", 0));
	}
	//list< pair < string, int > >::iterator it_lst;
	
}
bool LruCache::find_and_add(const std::string &address /*flg*/) // if true and add => if elem is in the end, the delete another
{
	auto it_err = addressMap.find(address);
	if(it_err == addressMap.end())
	{
		if(addressMap.size() == size)
		{
			//clear the tail of map and list
			auto it = list.end();
			auto it2 = addressMap.end();
			list.erase(it);
			addressMap.erase(it2);
		}
		//add new address to the top
		auto it2 = addressMap.begin(); 
		addressMap.insert(it2, pair<string, int>(address, 0));
		auto it = list.begin();
		list.insert(it, pair<string, int>(address, 0));
		size++;
		//list.push_front(pair<string, int>(address, 0));
		return false;
	}
	if(it_err != addressMap.end()) return true; //if iterator hasn't reached the end of map we have succh an address in cache
}
void LruCache::map_output()
{
	for (auto it = addressMap.begin(); it != addressMap.end(); it++)
	{
		cout << "\n";
		cout << (*it).first << ":" << (*it).second << "\n";
		cout << "\n";
	}
}
std::ostream& operator<<(std::ostream& ostr, const LruCache& obj)
{
	for(auto it = obj.addressMap.begin(); it != obj.addressMap.end(); it++)
	{
		ostr << (*it).first << ":" << (*it).second << "\n";
	}
	return ostr; 
}
// Lru_Cache::~Lru_Cache()
// {

// }
