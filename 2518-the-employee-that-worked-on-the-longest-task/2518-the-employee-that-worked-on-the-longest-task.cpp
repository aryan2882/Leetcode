class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int>ans;
        ans.push_back(logs[0][1]);
        for(int i=1;i<logs.size();i++){
            ans.push_back(logs[i][1]-logs[i-1][1]);
        }
        int mini=0;
        int index=-1;
        for(int i=0;i<ans.size();i++){
            if(mini<ans[i]){
                mini=ans[i];
                index=i;
            }
            else if(mini==ans[i]){
                if(logs[index][0]>logs[i][0]){
                    index=i;
                }
            }
        }
        return logs[index][0];
    }
};