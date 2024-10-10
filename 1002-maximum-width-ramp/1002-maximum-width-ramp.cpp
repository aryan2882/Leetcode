class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        int result=0;
        for(int j=nums.size()-1;j>=0;j--){
            while(!st.empty() && nums[st.top()]<=nums[j]){
                result = max(result, j - st.top());
                st.pop();
            }
        }
        return result;
    }
};