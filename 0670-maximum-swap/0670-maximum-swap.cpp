class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to manipulate digits
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Create a last occurrence array for digits 0-9
        vector<int> last(10, -1);
        
        // Fill the last occurrence array
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse the number and find the first place to swap
        for (int i = 0; i < n; ++i) {
            // Look for a larger digit to swap with the current digit
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the digits and return the result
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        
        // If no swap can improve the number, return the original number
        return num;
    }
};