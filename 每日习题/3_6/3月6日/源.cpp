//ѡ5
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

//ѡ��10
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
//		// ����+=��cur
//		if (str[i] >= '0' && str[i] <= '9')
//			cur += str[i];
//		else
//		{
//			// �ҳ��������ַ�����������ַ���
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
//	int count[100] = { 0 };//������0��Ȼ������n�����Ӧλ�ü�1������������
//	int x = 0, n = 0; //�ҵ����ڵ���һ��������Ǹ�
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

