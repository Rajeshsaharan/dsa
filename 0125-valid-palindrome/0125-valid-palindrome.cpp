class Solution {
public:
    bool isPalindrome(string s) {
        string correct_string ="";
        int i =0;
        while( i < s.size()){
            if(s[i] >= 65 && s[i] <= 90  ||  s[i] >= 97 && s[i] <=122 || s[i] >= 48 && s[i]  <= 57){
                if(s[i] >=65 && s[i] <=90){
                    //means char is uppercase 
                    //to store in lowercase we add 32 to 
                    char single_char = s[i] +32;
                    correct_string.push_back(single_char);
                }else{
                    correct_string.push_back(s[i]);
                }
            }
            ++i;
        }
        int flag = true;
        i = 0;
        while(i < correct_string.size()/2){
            if(correct_string[i] != correct_string[correct_string.size() - i -1 ]){
                flag = false;
            }
            i++;
        }
        return flag;
        
    }
};