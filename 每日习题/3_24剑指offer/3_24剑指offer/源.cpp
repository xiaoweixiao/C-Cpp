#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 0;
		size_t i = 0;
		while (numbers[i] == 0)
		{
			count++;
			i++;
		}
		while (i<numbers.size()-1)
		{
			if (numbers[i] + 1 != numbers[i + 1])
			{
				int sub = numbers[i + 1] - numbers[i];
				if (sub < count)
					count -= sub;
				else
					return false;
			}
			i++;
		}
		return true;
	}
};

int main()
{

}