class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                if(st.empty()){
                    st.push(asteroids[i]);
                }
                else{
                    while(!st.empty()&& st.top()>0 &&st.top()<abs(asteroids[i]) ){
                        st.pop();
                    }
                    
                    if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                    else if(st.top()==abs(asteroids[i])){
                        st.pop();
                    }
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};