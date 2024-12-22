class Solution {
private:
    string helper(string command, int i, string answer) {
        if (i >= command.size()) {
            return answer;
        }
        if (command[i] == '(' && command[i + 1] == ')') {
            answer.push_back('o');
            i = i + 2;
            return helper(command, i, answer);
        }else if(command[i] == 'G'){
            answer.push_back('G');
            return helper(command, i+1, answer);
        }else{
            answer.push_back('a');
            answer.push_back('l');
            i = i +4;
            return helper(command, i, answer);
        }
    };

public:
    string interpret(string command) {
        string answer = "";
        return helper(command, 0, answer);

    };
};