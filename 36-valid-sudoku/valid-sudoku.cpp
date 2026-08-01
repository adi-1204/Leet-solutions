class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        unordered_set<char> st;
        for (int k = 0; k < 9; k += 3) {
            for (int l = 0; l < 9; l += 3) {
                for (int i = k; i < k + 3; i++) {
                    for (int j = l; j < l + 3; j++) {
                        if (mat[i][j] == '.')
                            continue;
                        if (st.count(mat[i][j]))
                            return false;
                        else
                            st.insert(mat[i][j]);
                    }
                }
                st.clear();
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] == '.')
                    continue;
                if (st.count(mat[i][j]))
                    return false;
                else
                    st.insert(mat[i][j]);
            }
            st.clear();
        }
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (mat[i][j] == '.')
                    continue;
                if (st.count(mat[i][j]))
                    return false;
                else
                    st.insert(mat[i][j]);
            }
            st.clear();
        }
        return true;
    }
};