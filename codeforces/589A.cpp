/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

const int MAXN = 20000 + 100;

class Node{
public:
	char str[200];
	char login[200], ads[200];
};

Node ori[MAXN];

char toL(char x)
{
	if ( x >= 'A' && x <= 'Z' ) return (x - 'A') + 'a';
	else return x;
}

void xxx(int x)
{
	int len = strlen(ori[x].str);
	int sig = 0, pos = 0; 
	while ( ori[x].str[sig] != '@' ) ori[x].login[pos++] = toL(ori[x].str[sig++]);
	ori[x].login[pos] = '\0';pos = 0;sig++;
	while ( sig <= len ) ori[x].ads[pos++] = toL(ori[x].str[sig++]);

	pos = 0;
	len = strlen(ori[x].login);
	if ( !strcmp(ori[x].ads, "bmail.com") ) {
		for (int i = 0; i < len; i++){
			if ( ori[x].login[i] == '.' ) continue;
			else if ( ori[x].login[i] == '+' ) break;
			else ori[x].login[pos++] = ori[x].login[i];
		}
		ori[x].login[pos] = '\0';
	}
}

bool mCmp(const Node a, const Node b)
{
	if ( strcmp(a.ads, b.ads) ) return (strcmp(a.ads, b.ads) < 0);
	else return (strcmp(a.login, b.login) < 0);
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", ori[i].str);
		xxx(i);
	}
	
	sort(ori, ori + n, mCmp);
// 	for (int i = 0; i < n; i++){
// 		printf("%s\n", ori[i].str);
// 		printf("%s  %s\n", ori[i].login, ori[i].ads);
// 	}

	ori[n].login[0] = ori[n].ads[0] = '$';
	int ans = 0;
	int sig = 0, num = 1;
	for (int i = 1; i <= n; i++){
		if ( strcmp(ori[i].login, ori[sig].login) || strcmp(ori[i].ads, ori[sig].ads) ){
			ans++;
			sig = i;
		}		
	}
	sig = 0;
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++){
		if ( !strcmp(ori[i].login, ori[sig].login) && !strcmp(ori[i].ads, ori[sig].ads) ) num++;
		else {
			printf("%d ", num);
			for (int j = sig; j < i; j++){
				printf("%s%c", ori[j].str, (j == i-1)? '\n':' ');
			}
			sig = i;
			num = 1;
		}
	}

	return 0;
}*/