class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> arr;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                arr.push_back(abs(nums[i]-nums[j]));
            }
        }
        nth_element(arr.begin(),arr.begin()+(k-1),arr.end());
        return arr[k-1];
    }
};