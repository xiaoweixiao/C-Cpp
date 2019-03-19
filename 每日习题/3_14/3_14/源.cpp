//完全正确
//class Board {
//public:
//	bool checkWon(vector<vector<int> > board) {
//		if (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
//			return true;
//		if (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
//			return true;
//		for (int i = 0; i < 3; i++)
//		{
//			if (board[i][0] == 1 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
//				return true;
//			if (board[0][i] == 1 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
//				return true;
//		}
//		return false;
//	}
//};


//完全正确
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		size_t point = 0, n = 0, c = 0, s = 0, C = 0;
//		size_t len = str.size();
//		if (len < 5)point += 5;
//		else if (len < 8)point += 10;
//		else if (len>7) point += 25;
//		else
//			cout << "Unkonw error" << endl;
//		for (size_t i = 0; i < str.size(); i++)
//		{
//			if (str[i] >= '0'&&str[i] <= '9')
//				n++;
//			else if (str[i] >= 'a'&&str[i] <= 'z')
//				c++;
//			else if (str[i] >= 'A'&&str[i] <= 'Z')
//				C++;
//			else
//				s++;
//		}
//		if (c&&C)point += 20;
//		else if ((!c&&C) || (c&&!C))point += 10;
//		
//		if (n > 1)point += 20;
//		else if (n == 1)point += 10;
//		
//		if (s > 1)point += 25;
//		else if (s == 1)point += 10;
//
//		if (s&&n&&c&&C)point += 5;
//		else if (n&&s && ((!c&&C) || (c&&!C)))point += 3;
//		else if (((!c&&C) || (c&&!C)) && n)point += 2;
//
//		if (point >= 90)
//			cout << "VERY_SECURE" << endl;
//		else if (point >= 80)
//			cout << "SECURE" << endl;
//		else if (point >= 70)
//			cout << "VERY_STRONG" << endl;
//		else if (point >= 60)
//			cout << "STRONG" << endl;
//		else if (point >= 50)
//			cout << "AVERAGE" << endl;
//		else if (point >= 25)
//			cout << "WEAK" << endl;
//		else if (point >= 0)
//			cout << "VERY_WEAK" << endl;
//	}
//}