class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi=0;
        int small=arrays[0][0];
        int large=arrays[0][arrays[0].size()-1];
        for(int i=1;i<arrays.size();i++){
            maxi=max(maxi,abs(small-arrays[i][arrays[i].size()-1]));
            maxi=max(maxi,abs(large-arrays[i][0]));
            small=min(small,arrays[i][0]);
            large=max(large,arrays[i][arrays[i].size()-1]);
        }
        return maxi;
    }
};