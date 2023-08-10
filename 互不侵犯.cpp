//
// Created by Mori on 2023/7/14.
//

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int read () {
	int res = 0;
	bool f = false;
	char temp = getchar();
	for (; !isdigit(temp); temp = getchar()) f = temp == '-';
	for (; isdigit(temp); temp = getchar()) res = res * 10 + temp - '0';
	if (f) return -res;
	return res;
}

char gc () {
	char temp = getchar();
	while (temp == '\n' || temp == '\r' || temp == ' ') temp = getchar();
	return temp;
}

constexpr int maxn = 1 << 10;
int n, m, ctz[maxn];
ll dp[10][100][maxn];
vector <int> avb;

int main () {
	n = read(), m = read();
	int s = (1 << n) - 1;
	for (int i = 0; i <= s; i++) {
		ctz[i] = __builtin_popcount(i);
		if (!(((i << 1) | (i >> 1)) & i))
			avb.emplace_back(i);
	}
	dp[0][0][0] = 1;
//	for (int i : avb) dp[0][0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= j; ++k) {
				for (int x : avb) {
					if (ctz[x] == k) {
						for (int y : avb) {
							if (not(x & y) and not(x << 1 & y) and not(x >> 1 & y)) {
								dp[i][j][x] += dp[i - 1][j - k][y];
							}
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i : avb) ans += dp[n][m][i];
	printf("%lld\n",ans);
	return 0;
}