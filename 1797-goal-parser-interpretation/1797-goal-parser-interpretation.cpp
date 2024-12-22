class Solution {
public:
    string interpret(string command) {
        int size = command.size();
        string answer = "";
        int i =0;
        while(i < size){
            if(command[i] == '(' && command[i+1] == ')'){
                answer.push_back('o');
                i = i +2;
            }else if (command[i] == 'G'){
                answer.push_back('G');
                i = i+1;
            }else{
                answer.push_back('a');
                answer.push_back('l');
                i= i+4;
            }
        }
        return answer;
        
    }
};