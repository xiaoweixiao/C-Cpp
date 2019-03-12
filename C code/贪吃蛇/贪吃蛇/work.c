
#include<Windows.h>

int main()
{
	while (1){
		SHORT r = GetAyncKeyState(VK_UP);
		printf("%d\n",r);

	}
}