#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct PID{
	double e;						//e(t)
	double e1;						//e(t)的前一时刻
	double e2;						//e1的前一个时刻
	double u;						//u(t）
	double u1;						//u(t)的前一时刻
	double Kp, Ki, Kd;				//比例、积分、微分系数
	double integral;				//积分值
};

//0.323, 0.357, 0.0553;
void InitPID(PID& pid,double Kp, double Ki, double Kd)
{
	pid.Kp = Kp;
	pid.Ki = Ki;
	pid.Kd = Kd;
	pid.e = 0.0;						
	pid.e1 = 0.0;
	pid.e2 = 0.0;
	pid.u = 0.0;
	pid.u1 = 0.0;
	pid.integral = 0.0;
}
double PidPosition(PID& pid,double R,double y1)//位置式pid
{
	pid.e = R - y1;//e=R-y
	pid.integral += pid.e;
	pid.u = pid.Kp*pid.e + pid.Ki*pid.integral + pid.Kd*(pid.e - pid.e1);//u(k)=Kp*e+Ki*pid.integral+Kd*(e-e1)
	pid.e1 = pid.e;
	pid.u1 = pid.u;
	return pid.u;
}

double increment;
double PidIncrement(PID& pid,double R,double y1)//增量式PID
{
	pid.e = R - y1;
	increment = pid.Kp*(pid.e - pid.e1) + pid.Ki*pid.e + pid.Kd*(pid.e - 2 * pid.e1 + pid.e2);
	pid.u += increment;
	pid.e2 = pid.e1;
	pid.e1 = pid.e;
	return pid.u;
}

double Transfer(PID& pid,double input)//u=0.5u1+0.5e1//传递函数
{
	return 0.5*pid.u1+ + 0.5*pid.e1;
}

int main()
{
	double Kp = 0.0, Ki = 0.0, Kd = 0.0;
	PID pid;
	double R = 0.0, y = 0.0, y1 = y;
	printf("请输入Kp,Ki,Kd:>");
	scanf("%lf%lf%lf", &Kp, &Ki, &Kd);
	InitPID(pid,Kp,Ki,Kd);
	cout << "PID begin>\n";
	for (int i = 0; i < 1000; i++)//单位阶跃信号
	{
		if (i < 50)
			R = 0;
		else
			R = 1;
	}

	double et = 0.0;//传递函数的输入值
	for (int i = 0; i <200; i++)
	{
		et = PidPosition(pid, 1, y1);//PID的结果u(t)是传递函数的输入
		y1 = y;//y1是上一个系统输出，负反馈到PID部分，PID的e(t)=R-y1,R是系统输入
		y = Transfer(pid, et);
		printf("%lf\n", y);
	}
	system("pause");
	return 0;
}