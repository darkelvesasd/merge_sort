class Solution {
public:
void merge(vector<int>&arr,int n)
{
	int gap = 1;
	vector<int>t(n + 1);
	while (gap <= n)
	{
		for (int i = 0; i <= n; i+=2*gap)
		{
			int b1 = i;
			int e1 = i + gap-1;
			int b2 = i + gap;
			int e2 = i + 2 * gap - 1;
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
			while (b1<=e1&&b2<=e2)
			{
				if (arr[b1] < arr[b2])
				{
					t[j++] = arr[b1++];
				}
				else
				{
					t[j++] = arr[b2++];
				}
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
}
    vector<int> sortArray(vector<int>& nums) {
	merge(nums,nums.size()-1);
	return nums;
    }
};
