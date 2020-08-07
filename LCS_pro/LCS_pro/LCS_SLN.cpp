#include"LCS_heads.h"

#pragma region func_udef
void LCS_(string st1, string st2);//非连续，最长子序列
void LCS_str(string& st1, string& st2);//连续，最长子串
void LCS_inc(string& st1, string& st2);//递增子序列
#pragma endregion

int main()
{
	string bb = "aabbccddeeff";
	string aa = "aaacccbbddf";
	LCS_(aa, bb);
	return 0;
}

#pragma region udef_func_construct

#pragma endregion

void LCS_(string st1, string st2)//非连续，最长子序列
{
	//动态规划实现
	vector<string>cv_st1, cv_st2;
	cv_st1.push_back(st1);
	cv_st2.push_back(st2);
	int size_tab_Row = (cv_st1[0].size()) + 1;
	int size_tab_Col = (cv_st2[0].size()) + 1;
	vector<vector<int>>Tab_st(size_tab_Row);
	for (int i = 0; i < size_tab_Row; i++)
	{
		Tab_st[i].resize(size_tab_Col);
		for (int j = 0; j < size_tab_Col; j++)
		{
			Tab_st[i][j] = 0;
		}
	}
	for (int i = 1; i < size_tab_Row; i++)
	{
		for (int j = 1; j < size_tab_Col; j++)
		{
			if (cv_st1[0].at(i - 1) == cv_st2[0].at(j - 1))
			{
				Tab_st[i][j] = Tab_st[i - 1][j - 1] + 1;
			}
			else
			{
				Tab_st[i][j] = Tab_st[i - 1][j] > Tab_st[i][j - 1] ? Tab_st[i - 1][j] : Tab_st[i][j - 1];
			}
		}
	}//save strategy
	string outstr_ = "";
	for (int col = size_tab_Row - 1; col > 0; col--)
	{
		int max;
		max = Tab_st[col][size_tab_Col - 1];
		for (int row = size_tab_Col - 1; row > 0; row--)
		{
			if (Tab_st[col][row] < max)
			{
				char c;
				c = cv_st1[0].at(row + 1);
				outstr_.append(1, c);
				cout << c << endl;
				break;
			}
			max = Tab_st[col][row];
		}
	}
	//reverse to cout the substring
	reverse(outstr_.begin(), outstr_.end());
	cout << outstr_ << endl;

}
void LCS_str(string& st1, string& st2)//连续，最长子串
{

}
void LCS_inc(string& st1, string& st2)//递增子序列
{

}