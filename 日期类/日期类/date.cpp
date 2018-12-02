#include"date.h"
void Testconstruct()
{
	date d1(2018, 6);//2018,6,1,6
	d1.Show();

	date d2(d1);//2018,6,16
	d2.Show();
	date d3 = d2 - -4000;//2029,5,29
	d3.Show();
	date d4 = d3 + -4000;//2018,6,1
	d4.Show();

	cout << (d3 - d2) << endl;
}
void TestSybol()
{
	date d2(2018, 6);//2018,6,1,6
	d2.Show();

	date d3 = d2 + 4000;//2029,5,29
	d3.Show();

	cout << "(d3>d2)?" << (d3 > d2) << "(d3<d2)?" << (d3 < d2) << endl;
	cout << "(d3>=d2)?" << (d3 >= d2) << "(d3<=d2)?" << (d3 <= d2) << endl;
	cout << "(d3==d2)?" << (d3 == d2) << "(d3!=d2)?" << (d3 != d2) << endl;
}
int main()
{
	Testconstruct();
	//TestSybol();
	system("pause");
	return 0;
}