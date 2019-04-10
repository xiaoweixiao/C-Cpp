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

//编程1题
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string in, ret, cur;
//	cin >> in;
//	//这里注意i要遍历到in.size()，因为最长的那个字符可能是abcd12345ed125ss123456789
//	//而in.size()是不可见字符不是数字，就会去判断当前cur的长度
//	for (size_t i = 0; i <= in.size(); i++)
//	{
//		if (in[i] >= '0'&&in[i] <= '9')
//			cur += in[i];
//		else
//		{
//			if (cur.size()>ret.size())//比ret长替换ret
//				ret = cur;
//			else
//				cur.clear();
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


//编程2题
//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	map<int, int> in;
//	int num, n = 0;
//	while (cin >> num)
//	{
//		in[num]++;
//		n++;
//	}
//
//	for (size_t i = 0; i<in.size(); i++)
//	{
//		if (in[i] >= n / 2)
//		{
//			cout << i << endl;
//			return 0;
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	vector<int> in;
	while (cin >> num)
		in.push_back(num);

	int count = 1;
	int ret = in[0];
	for (size_t i = 1; i<in.size(); i++)
	{
		if (ret == in[i])
			count++;
		else
			count--;
		if (count == 0)//i走过的路径中，ret出现次数少于没出现次数
		{
			ret = in[i];
			count = 1;
		}
	}
	//一定存在出现次数大于等于长度一半的，ret最终指向的就是这个数
	cout << ret << endl;
	return 0;
}