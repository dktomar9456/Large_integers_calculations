
#include<bits/stdc++.h>
using namespace std;

string addition(string a, string b);
string subtraction(string a, string b);
string multiplication(string a, string b);
string devision(string a, string b);
string factorial(string a);

bool is_operator(char ch)
{

	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '!');
}
//**************************************Main function**********************************
int main()
{
	string a, b;
	string input;

start:
	getline(cin, input, '\n');

	char op;
	int n = input.length();

	if (input[0] == '!')
	{
		op = '!';
		a = input.substr(1, n - 1);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (is_operator(input[i]))
			{
				op = input[i];
				b = input.substr(i + 1, n - i);
				break;
			}
			a.push_back(input[i]);
		}
	}
	cout << " = " ;
	string ans;
	switch (op)
	{
	case '+':  ans = addition(a, b);
		cout << ans;
		break;
	case '-': ans = subtraction(a, b);
		cout << ans;
		break;
	case '*': ans = multiplication(a, b);
		cout << ans;
		break;
	// case '/': devision(a, b); break;
	// case '!': factorial(a); break;
	default : cout.flush() << "No OPERATOR FOUND! TRY AGAIN" << endl;
		input.clear();
		a.clear(), b.clear();
		goto start;
	}
	return 0;
}

//********************************  Function For Addition  *********************************
string addition(string a, string b)
{
	int len_a = a.length(), len_b = b.length(), carry = 0, sum = 0;
	string result ;
	for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; i--, j--)
	{	sum = 0;
		if (i >= 0)
			sum += int(a[i] - 48);
		if (j >= 0)
			sum += int(b[j] - 48);
		result.push_back(char((sum + carry) % 10 + 48));
		carry = (sum + carry) / 10;

	}
	if (carry != 0)
	{
		result.push_back(char((carry) % 10 + 48));
	}
	int n = result.length();
	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		swap(result[i], result[j]);

	}
	return result;
}

//************************************  function for Subtraction   ************************
string subtraction(string a, string b)
{
	int len_a = a.length(), len_b = b.length(), val;
	string result, temp ;
	for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; i--, j--)
	{
		if (j >= 0)
		{
			if (a[i] >= b[j])
				val = int(a[i] - b[j]);
			else
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (a[k] == '0')
						a[k] = '9';
					else
					{
						a[k]--;
						break;
					}
				}
				val = 10 + int(a[i] - b[j]);
			}
		}
		else
			val = int(a[i] - 48);

		temp.push_back(char(val + 48));

	}
	int m = temp.length() - 1;
	while (temp[m] == '0')
		m--;
	for (int i = m; i >= 0; i--)
	{
		result.push_back(temp[i]);
	}

	return result;

}

//*********************************  function for multplication  ***************************
string multiplication(string a, string b)
{
	int len_a = a.length(), len_b = b.length(), carry = 0, temp;
	vector<string> result;
	for (int i = len_a - 1; i >= 0 ; i--)
	{	string temp_res;
		carry = 0;
		for (int j = len_b - 1; j >= 0; j--)
		{
			temp = int(a[i] - 48);
			temp *= int(b[j] - 48);
			int val = temp + carry;
			temp_res.push_back(char((val) % 10 + 48));
			carry = val / 10;
		}
		if (carry != 0)
			temp_res.push_back(char(carry % 10 + 48));
		string zeros = string(len_a - 1 - i, '0');
		temp_res += zeros;
		result.push_back(temp_res);

	}
	for (int i = 1; i < result.size(); i++)
	{
		result[i] = addition(result[i], result[i - 1]);
	}

	return result[result.size() - 1];
}