class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int nextsmall[n],prevsmall[n];
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(s1.empty()){
                prevsmall[i]=0;
            }
            else{
                prevsmall[i]=s1.top()+1;
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(s2.empty()){
                nextsmall[i]=n-1;
            }
            else{
                nextsmall[i]=s2.top()-1;
            }
            s2.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(nextsmall[i]-prevsmall[i]+1));
        }
        return maxi;

    }
};