class Solution {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int>ans(n, 1);
		for (int i = 0; i < n; i++) {
			int prev = ratings[i];
			int next = ratings[i];
			if (i >= 1)prev = ratings[i - 1];
			if (i + 1 < n)next = ratings[i + 1];
			if (ratings[i] > prev)
				ans[i] = max(ans[i - 1] + 1, ans[i]);
			if (ratings[i] > next)
				ans[i] = max(ans[i + 1] + 1, ans[i]);
		}
		for (int i = n - 1; i >= 0; i--) {
			int prev = ratings[i];
			int next = ratings[i];
			if (i >= 1)prev = ratings[i - 1];
			if (i + 1 < n)next = ratings[i + 1];
			if (ratings[i] > prev)
				ans[i] = max(ans[i - 1] + 1, ans[i]);
			if (ratings[i] > next)
				ans[i] = max(ans[i + 1] + 1, ans[i]);
		}
		int sum = 0;
		for (auto &it : ans)
			sum += it;
		return sum;
	}
};