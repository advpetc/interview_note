class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        return method2(nums1, nums2);
    }

    vector<int> method1(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (s.count(a))
                res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }

    // sort + two pointer
    vector<int> method2(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        int i = 0, j = 0;
        // nlog(n)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                ++i;
            else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                if (ret.empty() || ret.back() != nums1[i])
                    ret.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return ret;
    }

    // binary search method
    vector<int> method3(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> ret;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a))
                ret.insert(a);
        }
        return vector<int>(ret.begin(), ret.end());
    }

    /*! \brief binary search
     *
     *  log n
     *
     * \param Parameter Parameter description
     * \param Parameter Parameter description
     * \return exit or not
     */
    bool binarySearch(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
};
