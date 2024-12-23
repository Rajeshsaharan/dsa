class Solution {
public:
    bool is_contains(vector<int>& arr, int target){
        int i =0;
        int size = arr.size();
        if(size == 0){
            return false;
        }
        while(i < arr.size()){
            if(arr[i] == target){
                return true;
            }
        }
        return false;
    };

    bool uniqueOccurrences(vector<int>& arr) {
        int length = arr.size();
        unordered_map<int, int> umap;
        vector<int> result;
        int i = 0;
        int index =0;
        while(i < length){
            umap[arr[i]] = umap[arr[i]] +1;
            ++i;
        }
        auto it= umap.begin();
        while( it != umap.end()){
            if( count(result.begin(), result.end(), it->second) > 0){
                return false;
            }else{
               result.push_back(it->second);
            }
            ++it;
        }
       return true;
    }
};