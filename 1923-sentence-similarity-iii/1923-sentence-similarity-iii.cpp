class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        unordered_map<string,int> mp;
        stringstream ss(sentence1);
        string word;
        vector<string> words1;
        while(ss>>word){
            words1.push_back(word);
            
        }
        stringstream ss1(sentence2);
        string word1;
        vector<string> words2;
        while(ss1>>word1){
            words2.push_back(word1);
        }
        if (words1.size() < words2.size()) swap(words1, words2);
        
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        while (start < n2 && words1[start] == words2[start]) start++;
     
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        
        return start + end >= n2;
    }
};