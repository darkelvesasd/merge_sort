class Solution {
public:
int merge(vector<int>&nums,int n)
{
	int sum = 0;
	int gap = 1;
	vector<int>t(n+1);
	while (gap <= n)
	{
		for (int i=0;i<=n;i+=2*gap)
		{
			int b1 = i;
			int e1 = i + gap - 1;
			int b2 = i + gap;
			int e2 = i + gap * 2-1;
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
				if (nums[b1] <= nums[b2])
				{
					t[j++] = nums[b1++];
					sum += (b2 - e1-1);
				}
				else if (nums[b1] > nums[b2])
				{
					t[j++] = nums[b2++];
				}
			}
			if (b1 <= e1)
			{
				sum += (e2-e1)*(e1 - b1+1);
			}
			while (b1 <= e1)
			{
				t[j++] = nums[b1++];
			}
			while (b2<=e2)
			{
				t[j++] = nums[b2++];
			}
		}
		nums = t;
		gap *=2;
	}
	return sum;
}
    int reversePairs(vector<int>& record) {
int n = record.size();
	return merge(record,n-1);
    }
};
