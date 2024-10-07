class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()){
            return "0";
        }
        stack<char> st;
        for(int i=0;i<num.size();i++){
            char c=num[i];
            
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";

        while(!st.empty()){
            ans+=st.top();
            
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        ans.erase(0, ans.find_first_not_of('0'));
        if(ans==""){
            return "0";
        }
    return ans;
    }
};