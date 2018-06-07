#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, d;
vector<int> cnt(10, 0);

//GAYYYYYYYYYYY
int fpow(int x,int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD;
		y >>= 1;
	}
	return res;
}

//GAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
int calc() {
	int all = 0; for (int i = 0;i < 10;++i) all += cnt[i];
	int fact = 1; for (int i = 1;i <= all;++i) fact = 1LL * fact * i % MOD;
	for (int i = 0;i < 10;++i) {
		int f = 1;
		for (int j = 1;j <= cnt[i];++j) {
			f = 1LL * f * j % MOD;
		}
		fact = 1LL * fact * fpow(f, MOD - 2) % MOD;
	} 
	
	int pw = 1;
	int sumpw = 0;
	for (int i = 1;i <= all;++i) {
		sumpw += pw;
		if (sumpw >= MOD) sumpw -= MOD;
		pw = 1LL * pw * 10 % MOD;
	}
	//GAYYYAYYAYSYAYSYAYSYAYAY
	int res = 0;
	for (int i = 0;i < 10;++i) {
		int f = fact;
		f = 1LL * f * cnt[i] % MOD;
		f = 1LL * f * fpow(all, MOD - 2) % MOD;
		res += 1LL * f * sumpw % MOD * i % MOD;
		if (res >= MOD) res -= MOD;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		cin >> d;
		cnt[d]++;
	}
	int res = calc();
	if (cnt[0]) {
		cnt[0]--;
		res -= calc();
		if (res < 0) res += MOD;
	}
	cout << res << endl;
}
