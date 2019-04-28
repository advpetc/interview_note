class Solution {
    public:
        int partition(vector<int>& nums, int left, int right)
        {
            // could also be a random number
            int pivot = nums[left];
            int l = left + 1, r = right;
            while (l <= r)
            {
                // swap to make sure all then num on the left are smaller than pivot
                // right are greater than pivot
                if (nums[l] < pivot && nums[r] > pivot) 
                    swap(nums[l++], nums[r--]);
                if (nums[l] >= pivot) l++;
                if (nums[r] <= pivot) r--;
            }
            swap(nums[left], nums[r]);
            return r;
        }

        int findKthLargest(vector<int>& nums, int k) {
            // quick select
            int left = 0, right = nums.size() - 1;
            while (true)
            {
                int pos = partition(nums, left, right);
                if (pos + 1 == k)
                    return nums[pos];
                else if (pos + 1 > k)
                    right = pos - 1;
                else
                    left = pos + 1;
            }

        }
};
