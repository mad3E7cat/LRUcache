#pragma once
// #ifndef LRU_H
// #define LRU_H
#include <string>
#include <list>
#include <iterator>
#include <map> 
class LruCache
{
private:
	int size;
	int used;
	//list<string> addresses; // may be not string, struct with time stamp of last request and string
	std::list<std::pair<std::string, int>> list;
	std::map< std::string, int > addressMap; 
public:
	LruCache(int size = 0);
	bool find_and_add(const std::string &address); // returns true if address is found in cache
	void map_output();
	friend std::ostream& operator<<(std::ostream& ostr, const LruCache& obj);
};
#include "lru_cache.cpp"

// #endif