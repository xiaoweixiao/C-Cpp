#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

//class Front
//{
//public:
//	static Front* Get()
//	{
//		return &_data;
//	}
//private:
//	static Front _data;
//private:
//	Front(){};//构造
//	Front(const Front&) = delete;//拷贝构造
//	Front& operator=(const Front&) = delete;//赋值运算
//};
//Front Front::_data;//程序运行前就创建了对象

class Back
{
public:
	class GC//内嵌类---垃圾回收
	{
	public:
		~GC()
		{
			if (_data)
				delete _data;
		}
	};

	static Back* GetObj()
	{
		if (_data == nullptr)//如果没有创建对象才让线程去拿锁
		{
			_mutex.lock();
			if (_data == nullptr)
				_data = new Back();//创建对象
			_mutex.unlock();
		}
		return _data;
	}
private:
	Back(){}//构造函数
	Back(const Back&) = delete;//拷贝构造
	Back& operator=(const Back&) = delete;//赋值运算符
private:
	static Back* _data;
	static mutex _mutex;
	static GC _gc;
};

Back* Back::_data = nullptr;
mutex Back::_mutex;
Back::GC Back::_gc;

void Func()
{
	cout << Back::GetObj() << endl;
}
int main()
{
	/*Front*f = Front::Get();*/
	thread t1(Func);
	thread t2(Func);
	thread t3(Func);
	thread t4(Func);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	Func();
	system("pause");
	return 0;
}