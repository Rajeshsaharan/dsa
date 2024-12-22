using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int size = candyType.size();
        int i = 1;
        int count = 1;
        map<int, int> store;
        store[candyType[0]];
        while (i < size) {
            if (count < size / 2) {
                if (!store.count(candyType[i])) {
                    count++;
                    store[candyType[i]] = 0;
                } 
            }
            ++i;
        }
        return count;
    }
};