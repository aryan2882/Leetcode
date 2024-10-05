class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int j=i;
            while(j!=(i+n-1)%n){
                if(nums[j]>nums[i]){
                    ans[i]=nums[j];
                    break;
                }
                j=(j+1)%n;
            }
            if(j==(i+n-1)%n){
                if(nums[i]<nums[j]){
                    ans[i]=nums[j];
                }
                else{
                    ans[i]=-1;
                }
            }
        }
        return ans;
    }
};