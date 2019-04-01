//#include<iostream>
//#include<unordered_map>
//using namespace std;
//class Solution {
//public:
//	// Parameters:
//	//        numbers:     an array of integers
//	//        length:      the length of array numbers
//	//        duplication: (Output) the duplicated number in the array number
//	// Return value:       true if the input is valid, and there are some duplications in the array number
//	//                     otherwise false
//	bool duplicate(int numbers[], int length, int* duplication) {
//			unordered_map<int, int> mymap;
//			int The_Once = 0;
//			for (int i = 0; i < length; ++i)
//			{
//				if (!(mymap.insert(make_pair(numbers[i], 1))).second)
//				{
//					cout << numbers[i] << endl;
//					*duplication = numbers[i];
//					return 1;
//				}
//			}
//			return false;
//	}
//};
//int main()
//{
//	Solution s;
//	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
//	int length = sizeof(arr) / sizeof(int);
//	int output;
//	s.duplicate(arr, length, &output);
//}


//1,2,3,4,5
//120, 60, 40, 30, 24

