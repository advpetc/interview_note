class Solution {
public:
    int evalRPN(vector<string>& tokens) { return recursion_method(tokens); }

    /*! \brief Using stack
     *
     *  store all tokens into stack
     *
     * \param tokens inputs
     * \return results
     */
    int stack_method(vector<string>& tokens)
    {
        if (tokens.size() == 1)
            return stoi(tokens[0]);
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*"
                && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(num2 + num1);
                if (tokens[i] == "-")
                    st.push(num2 - num1);
                if (tokens[i] == "*")
                    st.push(num2 * num1);
                if (tokens[i] == "/")
                    st.push(num2 / num1);
            }
        }
        return st.top();
    }

    /*! \brief recursion way
     *
     *  recursively check: doing the same thing as stack does
     *
     * \param tokens inputs
     * \return result
     */
    int recursion_method(vector<string>& tokens)
    {
        int op = (int)tokens.size() - 1;
        return helper(tokens, op);
    }

    int helper(vector<string>& tokens, int& op)
    {
        string str = tokens[op];
        if (str != "+" && str != "-" && str != "*" && str != "/")
            return stoi(str);
        int num1 = helper(tokens, --op);
        int num2 = helper(tokens, --op);
        if (str == "+")
            return num2 + num1;
        if (str == "-")
            return num2 - num2;
        if (str == "*")
            return num2 * num1;
        return num2 / num1;
    }
};
