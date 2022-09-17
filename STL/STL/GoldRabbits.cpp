//#include "BigInt.h"
//
//static std::map<BigInt, BigInt> hashmap = { {BigInt(0), BigInt(1)} , {BigInt(1), BigInt(1)} };
//
//static std::map<int, int> rabbit = { {0,1},{1,1} };
//
//int goldRabbits(int n) {
//	if (rabbit.count(n) == 0) {
//		int result;
//		for (int iter = rabbit.rbegin()->first; iter <= n; ++iter) {
//			result = rabbit[iter - 1] + rabbit[iter - 2];
//			if (rabbit[iter - 1] > 0 && rabbit[iter - 2] > 0 && result < 0) throw std::string("Overflow Error - goldRabbits overflowed using " + std::to_string(iter));
//			rabbit.insert(std::pair<int, int>(iter, result));
//		}
//	}
//	return rabbit[n];
//}
//
//BigInt goldRabbits(BigInt n) {
//	if (hashmap.count(n) == 0) {
//		for (BigInt iter = hashmap.rbegin()->first; iter <= n; ++iter) {
//			hashmap.insert(std::pair<BigInt, BigInt>(iter, goldRabbits(iter - 2) + goldRabbits(iter - 1)));
//		}
//	}
//	return hashmap[n];
//}