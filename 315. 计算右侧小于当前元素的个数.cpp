class Solution {
public:
    void merge(vector<int>& arr, int n, vector<int>& hash, vector<int>& ret) {
        int gap = 1;
        vector<int> t(n + 1);
        vector<int> t1(n + 1);
        while (gap <= n) {
            for (int i = 0; i <= n; i += gap * 2) {
                int b1 = i;
                int e1 = gap + i - 1;
                int b2 = gap + i;
                int e2 = gap * 2 + i - 1;
                if (e1 > n) {
                    e1 = n;
                    break;
                }
                if (e2 > n) {
                    e2 = n;
                }
                int j = i;
                while (b1 <= e1 && b2 <= e2) {
                    if (arr[b1] > arr[b2]) {
                        ret[hash[b1]] += e2 - b2 + 1;
                        t1[j] = hash[b1];
                        t[j++] = arr[b1++];
                    }
                    if (arr[b1] <= arr[b2]) {
                        t1[j] = hash[b2];
                        t[j++] = arr[b2++];
                    }
                }
                while (b1 <= e1) {
                    t1[j] = hash[b1];
                    t[j++] = arr[b1++];
                }
                while (b2 <= e2) {
                    t1[j] = hash[b2];
                    t[j++] = arr[b2++];
                }
            }
            arr = t;
            hash = t1;
            gap *= 2;
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            hash[i] = i;
        }
        merge(nums, nums.size() - 1, hash, ret);
        return ret;
    }
};
