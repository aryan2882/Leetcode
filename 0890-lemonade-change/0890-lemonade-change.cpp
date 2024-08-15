class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cost1=0,cost2=0;
     for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            cost1+=1;
        }
        else if(bills[i]==10){
            cost2+=1;
            if(cost1>0){
                cost1--;
            }
            else{
                return false;
            }
        }
        else{
            if(cost1>0 && cost2>0){
                cost1--;
                cost2--;
            }
            else if(cost1>2){
                cost1-=3;
            }
            else{
                return false;
            }
        }
        

     }  
     return true; 
    }
};