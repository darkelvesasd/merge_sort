class Solution {
public:
int merge(vector<int>&arr,int n)
{
	int gap = 1;
	vector<int>t(n + 1);
	int sum = 0;
	while (gap<=n)
	{
		for (int i = 0; i <= n; i += gap * 2)
		{
			int b1 = i;
			int e1 = i + gap - 1;
			int b2 = i + gap;
			int e2 = i + gap * 2 - 1;
			if (e1 > n)
			{
				e1 = n;
				break;
			}
			if (e2 > n)
			{
				e2 = n;
			}
			int j = i;
			int left = b1;
			int right = b2;
			while (left <=e1&&right<=e2)
			{
				if (arr[left]>(long long)2*arr[right])
				{
					sum += e2-right+ 1;
					left++;
				}
				else
				{
					right++;
				}
			}
			while (b1<=e1&&b2<=e2)
			{
				t[j++] = arr[b1] > arr[b2] ? arr[b1++] : arr[b2++];
			}
			while (b1 <= e1)
			{
				t[j++] = arr[b1++];
			}
			while (b2 <= e2)
			{
				t[j++] = arr[b2++];
			}
		}
		arr = t;
		gap *= 2;
	}
	return sum;
}
    int reversePairs(vector<int>& nums) {
	return merge(nums, nums.size() - 1);
    }
};
