#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 4000 + 100;
class Node{
public:
	long long a, b;
};

Node p[MAXN];

bool mCmpA(const Node x, const Node y)
{
	return (x.a > y.a);
}

bool mCmpB(const Node x, const Node y)
{
	return (x.b < y.b);
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		cin>>p[i].a>>p[i].b;
		if ( p[i].a > p[i].b ) swap(p[i].a, p[i].b);
	}
	sort(p, p + n, mCmpA);
// 	for (int i = 0; i < n; i++){
// 		cout<<p[i].a<<"  "<<p[i].b<<endl;
// 	}
// 	cout<<endl;

	long long ans = 0;
	int l, r;
	for (int i = 0; i < n; i++){
		int tempA = p[i].a;
		sort(p, p + i + 1, mCmpB);
		for (int j = 0; j <= i; j++) {
			long long temp = tempA * p[j].b * (i+1-j);
			if ( temp > ans ){
				ans = temp;
				l = tempA;
				r = p[j].b;
			}
 		}
	}

	cout<<ans<<endl;
	cout<<l<<" "<<r<<endl;

	return 0;
}