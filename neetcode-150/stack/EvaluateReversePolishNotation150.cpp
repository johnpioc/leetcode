class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (string character : tokens) {
            if (
                character != "+" &&
                character != "-" &&
                character != "*" &&
                character != "/"
            ) {
                operands.push(stoi(character));
            } else {
                int operandB = operands.top();
                operands.pop();
                int operandA = operands.top();
                operands.pop();

                int result;

                if (character == "+") {
                    result = operandA + operandB;
                } else if (character == "-") {
                    result = operandA - operandB;
                } else if (character == "*") {
                    result = operandA * operandB;
                } else {
                    result = operandA / operandB;
                }
                
                operands.push(result);
            }
        }

        return operands.top();
    }
};