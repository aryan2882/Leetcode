class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int m=s1.size();
        int n=s2.size();
        vector<int> first(26,0),window(26,0);
        for(char c: s1){
            first[c-'a']++;
        }
        for(int i=0;i<m;i++){
            window[s2[i]-'a']++;
        }
        
        for(int i=0;i<=n-m;i++){
            if(first==window){
                return true;
            }
            if(i+m<n){
                window[s2[i]-'a']--;
                window[s2[i+m]-'a']++;
            }
        }
        return first==window;
    }
};