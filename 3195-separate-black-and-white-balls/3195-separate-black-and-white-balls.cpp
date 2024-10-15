class Solution {
public:
    long long minimumSteps(string s) {
        stack<char> st;
        long long cnt=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
            else{
                maxi+=cnt;
            }
        }
        return maxi;;
    }
};