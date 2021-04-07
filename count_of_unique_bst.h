#pragma once

#include <vector>

using std::vector;

int dfs(int i, int j, vector<int>& memo);

int count_bst(int n)
{
	vector<int> memo(n);
	return dfs(1, n, memo);
}

int dfs(int i, int j, vector<int>& memo)
{
	if (i > j) return 1;
	if (memo[j-i]) return memo[j-i];

	int res(0);
	for (int k = i; k <= j; ++k)
		res += dfs(i, k-1, memo) * dfs(k + 1, j, memo);

	memo[j-i] = res;
	return res;
}

//F(i, n) = G(i - 1) * G(n - i)