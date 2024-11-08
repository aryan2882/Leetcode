class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int a=pow(2,maximumBit)-1;
        int xorr=0;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            xorr^=nums[i];
        }
        for(int k=0;k<nums.size();k++){
            ans[k]=xorr^a;
            xorr^=nums[nums.size()-1-k];
        }
        return ans;
    }
};