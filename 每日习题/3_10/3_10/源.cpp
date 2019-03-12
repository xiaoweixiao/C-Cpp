//#include<iostream>
//using namespace std;
//int main()
//{
//	int num;
//	//0		1	1	2	3	5	8	13	21	
//	while (cin >> num)
//	{
//		int arr[40];
//		arr[0] = 0, arr[1] = 1;
//		int i = 2;
//		for (; i < 40; i++)
//			arr[i] = arr[i - 1] + arr[i - 2];
//
//		for (i=0;i < 40; i++)
//		{
//			if (arr[i]>num)
//				break;
//		}
//		int ret = (arr[i] - num) < (num - arr[i - 1]) ? arr[i] - num : num - arr[i - 1];
//		cout << ret << endl;
//	}
//	system("pause");
//}

#include<iostream>
#include<string>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		int count = 0;
		string::iterator it = A.begin();
		while (it != A.end())
		{
			if (count < 0)return false;
			if (*it == '(')
			{
				count++;
				it++;
			}
			if (*it == ')')
			{
				if (count <= 0)return false;
				count--;
				it++;
				if (it<A.end()&&*it != '(' && *it != ')' && *it != '\0')
					return false;
			}	
		}
		if (count != 0)
			return false;
		else 
			return true;
	}
};
int main()
{
	string str("(()a())");
	int len=str.size();
	Parenthesis p;
	cout << p.chkParenthesis(str, len) << endl;
	system("pause");
}