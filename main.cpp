#include <iostream>
#include "lru_cache.h"
#include <tuple>
using namespace std;

int main()
{
	// LruCache lru1(4);
	// lru1.map_output();
	// lru1.find_and_add("AEEDFA");
	// lru1.find_and_add("AAAAAA");
	// lru1.find_and_add("AE3DEA");
	// lru1.find_and_add("AE3D5A");
	// lru1.map_output();
	// cout << lru1.find_and_add("AE3DEB");
	// lru1.map_output();
	// cout << "operator<< demo:\n\n";
	// cout << lru1;
	tuple <string, int, bool> trip("hello", 0, true);
	cout << "\n" << get<0>(trip) << ":" << get<1>(trip) << ":" << get<2>(trip);

	return 0;
}	