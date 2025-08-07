class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize index to prevent overflow
                long long curIndex = index - minIndex;

                if (i == 0) first = curIndex;   // First index at this level
                if (i == size - 1) last = curIndex; // Last index at this level

                if (node->left) {
                    q.push({node->left, 2 * curIndex + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curIndex + 2});
                }
            }
            maxWidth = max(maxWidth, int(last - first + 1));
        }
        return maxWidth;
    }
};
