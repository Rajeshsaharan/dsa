using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int size = candyType.size();
        int i = 0;
        map<int , int> store;
        while( i < size){
            if(store.size() < size / 2){
                cout << store.size() << endl;
                store[candyType[i]] = store[candyType[i]] +1;
            }
        
        ++i;
        }
        cout << store.size() << endl;
        return store.size();
    }
};