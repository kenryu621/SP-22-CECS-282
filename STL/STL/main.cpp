//#include <iostream>
//#include <time.h>
//#include <iomanip>
//using namespace std;
//
//int goldRabbits(int); // prototype or signature
//
//int main()
//{
//	int const months = 12 * 10; // this is 10 years or 120 months
//	int start = time(0); // number of seconds since Jan 1, 1970
//	for (int i = 0; i < months; i++)
//	{
//		int current = time(0); // number of seconds since program started
//		cout << setw(5) << current - start << ":"; // print elapsed seconds
//		cout << " GoldRabbits(" << setw(2) << i << ") = ";
//		cout << setw(11) << goldRabbits(i) << endl;// the call to goldRabbits
//	}
//}
//
//// this is the goldRabbits function
//int goldRabbits(int n)
//{
//	if (n == 0 || n == 1)
//		return 1;
//	else
//		return goldRabbits(n - 1) + goldRabbits(n - 2);
//}