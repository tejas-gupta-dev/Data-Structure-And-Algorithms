// class Solution {
// public:
//     struct PairHash {
//         size_t operator()(const pair<int, int>& p) const {
//             return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
//         }
//     };
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         unordered_set<pair<int, int>, PairHash> st;

//         for (int j = 0; j < reservedSeats.size(); j++) {
//             st.insert({
//                 reservedSeats[j][0] - 1,
//                 reservedSeats[j][1] - 1
//             });
//         }

//         int ans = 0;

//         for (int j = 0; j < n; j++) {
//             int c = 0;

//             for (int k = 1; k < 9; k++) {

//                 if (st.find({j, k}) == st.end()) {
//                     c++;

//                     if (c == 4) {
//                         ans++;
//                         c = 0;
//                     }
//                 }
//                 else {
//                     c = 0;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^
                   (hash<int>()(p.second) << 1);
        }
    };

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_set<pair<int, int>, PairHash> st;
        unordered_set<int> rows;

        for (auto &seat : reservedSeats) {
            int r = seat[0] - 1;
            int c = seat[1] - 1;

            st.insert({r, c});
            rows.insert(r);
        }

        // Every completely empty row gets 2 families
        int ans = (n - rows.size()) * 2;

        // Process only affected rows
        for (int row : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Original seats 2,3,4,5
            for (int k = 1; k <= 4; k++) {
                if (st.find({row, k}) != st.end()) {
                    left = false;
                    break;
                }
            }

            // Original seats 4,5,6,7
            for (int k = 3; k <= 6; k++) {
                if (st.find({row, k}) != st.end()) {
                    middle = false;
                    break;
                }
            }

            // Original seats 6,7,8,9
            for (int k = 5; k <= 8; k++) {
                if (st.find({row, k}) != st.end()) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};