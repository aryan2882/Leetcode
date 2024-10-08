class Solution {
public:
    int minSwaps(string s) {
        int notb=0,swap=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                notb++;
            }
            else{
                if(notb==0){
                    swap++;
                    notb++;
                }
                else{
                    notb--;
                }
            }
        }
        return swap;
    }
};