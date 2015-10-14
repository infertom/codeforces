#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;
stringstream ans;
string temp;
bool flag = true;

void work(ll a, ll b, char ch1, char ch2)
{
	ll d = a / b;
	ll m = a % b;

	if ( b == 1 ) ans<<(d-1)<<ch1;
	else if ( m == 0 ){
		flag = false;
		return;
	}else{
		ans<<d<<ch1;
		work(b, m, ch2, ch1);
	}
}

int main()
{
	ll x, y;

	cin>>x>>y;
	ans.clear();
	
	if ( x < y ) work(y, x, 'B', 'A');
	else work(x, y, 'A', 'B');


	ans>>temp;
	if ( flag ) cout<<temp<<endl;
	else cout<<"Impossible"<<endl;

	return 0;
} 