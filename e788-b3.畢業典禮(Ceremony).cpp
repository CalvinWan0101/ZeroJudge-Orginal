#include<iostream>
#include<string>
using namespace std;
struct human
{
	int number;
	string id;
	string name;
};
//Point：會動到原本的順序，需要再改
//建立座號？？？
int main()
{
	int n;
	string buffer;
	human student[101];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> student[i].id >> student[i].name;
		student[i].number = i;
	}
	//Alphabet
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (student[i].id[student[i].id.length() - 1] > student[j].id[student[j].id.length() - 1])
			{
				buffer = student[i].id;
				student[i].id = student[j].id;
				student[j].id = buffer;
				buffer = student[i].name;
				student[i].name = student[j].name;
				student[j].name = buffer;
			}
	//First Number
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (student[i].id[0] > student[j].id[0] && student[i].id[student[i].id.length() - 1] == student[j].id[student[j].id.length() - 1])
			{
				buffer = student[i].id;
				student[i].id = student[j].id;
				student[j].id = buffer;
				buffer = student[i].name;
				student[i].name = student[j].name;
				student[j].name = buffer;
			}
	//ID
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 0; k <= 7; k++)
				if (student[i].id[k] > student[j].id[k] && student[i].id[0] == student[j].id[0] && student[i].id[student[i].id.length() - 1] == student[j].id[student[j].id.length() - 1])
				{
					buffer = student[i].id;
					student[i].id = student[j].id;
					student[j].id = buffer;
					buffer = student[i].name;
					student[i].name = student[j].name;
					student[j].name = buffer;
				}
	for (int i = 1; i <= n; i++)
		cout << student[i].id[student[i].id.length() - 1] << ": " << student[i].name << endl;
	return 0;
}
