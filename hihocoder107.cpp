#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	char letter;
	string w = "";
	vector<string> article;
	while (cin >> noskipws >> letter)
	{
		//letter = cin.get();
		if ((letter<'Z' + 1 && letter>'A' - 1) || (letter<'z' + 1 && letter>'a' - 1))
		{
			letter = tolower(letter);
			
			w.append(string(1, letter));
		}
		else
		{
			if (w != "")
			{
				article.push_back(w);
				w = "";
			}
			string s = { letter };
			if (s!=" ")
			{
				article.push_back(s);
			}
		}
	}
	bool firstword = true;
	for (int i = 0; i < article.size(); i++)
	{
		string a = article[i];
		if (a.size() == 1&& !isalpha(char(a[0])))
		{
			cout << a;
			if (a == ".")
			{
				firstword = true;
				
			}continue;
		}
		if (firstword)
		{
			a[0] = toupper(char(a[0]));
			firstword = false;
		}
		if (i > 0 && article[i - 1] != "\n")
		{
			cout << " ";
		}
		cout << a;
	}
}