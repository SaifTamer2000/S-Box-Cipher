#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>
#define viy vector<int>
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define all(v) ((v).begin()), ((v).end())
using namespace std;
void sboxe(int (&x) [8],int a,int (&k)[3])
{
	int temp[3],temps=0;
	int t[2];
	int u[2];
	int resu[4];
	resu[0] = x[(5-a)];
	resu[1] = x[(4-a)];
	temp[0] =  resu[0] ^ k[2] ;
	temp[1] =  resu[1] ^ k[1] ;
	temp[2] = resu[0] ^ k[0];
	for (int j = 0; j < 3; j++)
	{
		if (temp[j] == 1)
			temps += pow(2, j);
	}
	switch (temps)
	{
	case (0):
		{
			u[0] = 1;
			u[1] = 1;
			break;
		}
	case(1):
		{
			u[0] = 0;
			u[1] = 1; 
			break;
		}
	case(2):
	{
		u[0] = 0, u[1] = 0;
		break;
	}
	case(3):
	{
		u[0] = 1, u[1] = 0;
		break;
	}
	case(4):
	{
		u[0] = 0, u[1] = 1;
		break;
	}
	case(5):
	{
		u[0] = 0, u[1] = 0;
		break;
	}
	case(6):
	{
		u[0] = 1, u[1] = 1;
		break;
	}
	case(7):
	{
		u[0] = 1, u[1] = 0;
		break;
	}
	}
	t[0] = x[7-a] ^ u[0];
	t[1] = x[6-a] ^ u[1];
	resu[2] = t[0];
	resu[3] = t[1];
	for (int j = 0; j < 4; j++)
	{
		x[(7-j) - a] = resu[j];
	}
	return;
	
}
void sboxd(int(&x)[8], int a, int(&k)[3])
{
	int temp[3], temps = 0;
	int t[2];
	int u[2];
	int resu[4];
	resu[2] = x[(7 - a)];
	resu[3] = x[(6 - a)];
	temp[0] = resu[2] ^ k[2];
	temp[1] = resu[3] ^ k[1];
	temp[2] = resu[2] ^ k[0];
	for (int j = 0; j < 3; j++)
	{
		if (temp[j] == 1)
			temps += pow(2, j);
	}
	switch (temps)
	{
	case (0):
	{
		u[0] = 1;
		u[1] = 1;
		break;
	}
	case(1):
	{
		u[0] = 0;
		u[1] = 1;
		break;
	}
	case(2):
	{
		u[0] = 0, u[1] = 0;
		break;
	}
	case(3):
	{
		u[0] = 1, u[1] = 0;
		break;
	}
	case(4):
	{
		u[0] = 0, u[1] = 1;
		break;
	}
	case(5):
	{
		u[0] = 0, u[1] = 0;
		break;
	}
	case(6):
	{
		u[0] = 1, u[1] = 1;
		break;
	}
	case(7):
	{
		u[0] = 1, u[1] = 0;
		break;
	}
	}
	t[0] = x[5 - a];
	t[1] = x[4 - a];
	resu[0] = t[0] ^ u[0];
	resu[1] = t[1] ^ u[1];
	for (int j = 0; j < 4; j++)
	{
		x[(7 - j) - a] = resu[j];
	}
	return;
}
int main()
{
	vector<int>arr;
	int  biarr[8] = { 0,0,0,0,0,0,0,0 },i,result=0,temp,n,z;
	int key[3];
	bool en = false;
	string s,rei;
    input:
	cout << " Enter 1 for Encryption and 2 for Decryption : ";
	cin >> temp;
	if (temp == 1)
		en = true;
	else if (temp == 2)
		en = false;
	else
	{
		cout << "Invaild input please try again";
		goto input;
	}
	if (en)
	{
		cout << "Enter the desierd string for Encryption : ";
		cin >> s;
	}
	else
	{
		cout << "Enter the number of values : ";
		cin >> n;
		cout << "Enter the Values : ";
		arr.resize(n);
		for (  z = 0; z < n; z++)
		{
			cin >> arr[z];
		}

	}
	rei = s;
	cout << "Enter the key : ";
	for (int j = 0; j < 3; j++)
	{
		cin >> key[j];
	}
	
	if (en)
	{
		for (int l = 0; l < s.length(); l++)
		{
			result = 0;
			int n = int(s[l]);
			int orp = n;
			for (i = 0; n > 0; i++)
			{
				biarr[i] = n % 2;
				n /= 2;
			}
				sboxe(biarr, 0, key);
				sboxe(biarr, 4, key);
			for (int i = 7; i >= 0; i--)
			{
				if (biarr[i] == 1)
					result += pow(2, i);
			}
			rei[l] = ((result - 97) % 26) + 97;
			if (en)
				cout << s[l];
			cout << " " << orp << "  -> " << rei[l] << " " << result << endl;
		}
		cout << s << " -> " << rei;
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			result = 0;
			int p = int(arr[x]);
			int orp = p;
			for (i = 0; p > 0; i++)
			{
				biarr[i] = p % 2;
				p /= 2;
			}
			sboxd(biarr, 0, key);
			sboxd(biarr, 4, key);
			for (int i = 7; i >= 0; i--)
			{
				if (biarr[i] == 1)
					result += pow(2, i);
			}
			char ou = ((result - 97) % 26) + 97;
			char oi = orp;
		
			cout << oi;
			cout << " " << orp << "  -> " << ou << " " << result << endl;
		}
		
	}
	return 0;
	}
