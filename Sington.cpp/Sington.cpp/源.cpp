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
//	Front(){};//����
//	Front(const Front&) = delete;//��������
//	Front& operator=(const Front&) = delete;//��ֵ����
//};
//Front Front::_data;//��������ǰ�ʹ����˶���

class Back
{
public:
	class GC//��Ƕ��---��������
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
		if (_data == nullptr)//���û�д�����������߳�ȥ����
		{
			_mutex.lock();
			if (_data == nullptr)
				_data = new Back();//��������
			_mutex.unlock();
		}
		return _data;
	}
private:
	Back(){}//���캯��
	Back(const Back&) = delete;//��������
	Back& operator=(const Back&) = delete;//��ֵ�����
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