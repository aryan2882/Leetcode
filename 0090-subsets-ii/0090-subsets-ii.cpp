class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0,nums,arr,ds);
        return arr;
    }
    void solve(int index,vector<int>& nums,vector<vector<int>>& arr,vector<int>& ds){
        arr.push_back(ds);
        for(int i=index; i<nums.size(); i++) {
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, nums, arr, ds);
            ds.pop_back();
        }
    }
};