//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	vector<int> vec(arr, arr + len);
//
//	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//	{
//		cout << *it << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v(5, 10);
//	cout << v.size() << endl << v.capacity() << endl;
//	v.reserve(2);
//	cout << v.size() << endl << v.capacity() << endl;
//	for (vector<int>::const_iterator cit = v.cbegin(); cit != v.cend(); cit++)
//	{
//		cout << *cit << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	// 在pos位置插入数据，导致pos迭代器失效。
//	// insert会导致迭代器失效，是因为insert可
//	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.insert(it, 30);
//	cout << *it << endl; // 此处会导致非法访问
//	system("pause");
//	return 0;
//}
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	it=v.erase(it);
//	cout << *it << endl;
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<array>
//using namespace std;
//int main()
//{
//	array<int, 10> arr;
//	arr.fill(10);
//	for (size_t i = 0; i < arr.size(); i++)
//		cout << arr[i] << endl;
//	system("pause");
//}

#include<iostream>
#pragma warning(disable:4200)//使用柔性数组会发出警告，或者将柔性数组元素个数设置为1
using namespace std;

typedef struct st_type
{
	int i;
	int a[0]; //柔性数组成员
}type_a;
int main()
{
	int i = 0;
	type_a *p = (type_a*)malloc(sizeof(type_a)+100 * sizeof(int));
	//业务处理
	p->i = 100;
	for (i = 0; i<100; i++)
	{
		p->a[i] = i;
	}

	free(p);
	system("pause");
	return 0;
}

