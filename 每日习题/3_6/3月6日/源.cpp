//选5
//#include<iostream>
//using namespace std;
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	cout << (func());
//}

//选择10
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << "" << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str, res, cur;
//	cin >> str;
//	for (int i = 0; i < str.length(); i++)
//	{
//		// 数字+=到cur
//		if (str[i] >= '0' && str[i] <= '9')
//			cur += str[i];
//		else
//		{
//			// 找出更长的字符串，则更新字符串
//			if (res.length() < cur.length())
//				res = cur;
//			else
//				cur.clear();
//		}
//	}
//	if (res.length() < cur.length())
//		res = cur;
//	cout << res;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int count[100] = { 0 };//数组置0，然后输入n，则对应位置加1，最后遍历数组
//	int x = 0, n = 0; //找到大于等于一半次数的那个
//	while (cin >> x){
//		count[x]++;
//		n++;
//	}
//	for (int i = 0; i<n; i++){
//		if (count[i] >= n / 2)
//			cout << i << endl;
//	}
//	return 0;
//}

