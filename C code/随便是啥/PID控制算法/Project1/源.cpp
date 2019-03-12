#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct PID{
	double e;						//e(t)
	double e1;						//e(t)��ǰһʱ��
	double e2;						//e1��ǰһ��ʱ��
	double u;						//u(t��
	double u1;						//u(t)��ǰһʱ��
	double Kp, Ki, Kd;				//���������֡�΢��ϵ��
	double integral;				//����ֵ
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
double PidPosition(PID& pid,double R,double y1)//λ��ʽpid
{
	pid.e = R - y1;//e=R-y
	pid.integral += pid.e;
	pid.u = pid.Kp*pid.e + pid.Ki*pid.integral + pid.Kd*(pid.e - pid.e1);//u(k)=Kp*e+Ki*pid.integral+Kd*(e-e1)
	pid.e1 = pid.e;
	pid.u1 = pid.u;
	return pid.u;
}

double increment;
double PidIncrement(PID& pid,double R,double y1)//����ʽPID
{
	pid.e = R - y1;
	increment = pid.Kp*(pid.e - pid.e1) + pid.Ki*pid.e + pid.Kd*(pid.e - 2 * pid.e1 + pid.e2);
	pid.u += increment;
	pid.e2 = pid.e1;
	pid.e1 = pid.e;
	return pid.u;
}

double Transfer(PID& pid,double input)//u=0.5u1+0.5e1//���ݺ���
{
	return 0.5*pid.u1+ + 0.5*pid.e1;
}

int main()
{
	double Kp = 0.0, Ki = 0.0, Kd = 0.0;
	PID pid;
	double R = 0.0, y = 0.0, y1 = y;
	printf("������Kp,Ki,Kd:>");
	scanf("%lf%lf%lf", &Kp, &Ki, &Kd);
	InitPID(pid,Kp,Ki,Kd);
	cout << "PID begin>\n";
	for (int i = 0; i < 1000; i++)//��λ��Ծ�ź�
	{
		if (i < 50)
			R = 0;
		else
			R = 1;
	}

	double et = 0.0;//���ݺ���������ֵ
	for (int i = 0; i <200; i++)
	{
		et = PidPosition(pid, 1, y1);//PID�Ľ��u(t)�Ǵ��ݺ���������
		y1 = y;//y1����һ��ϵͳ�������������PID���֣�PID��e(t)=R-y1,R��ϵͳ����
		y = Transfer(pid, et);
		printf("%lf\n", y);
	}
	system("pause");
	return 0;
}