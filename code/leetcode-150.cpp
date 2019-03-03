// 150 逆波兰表达式求值 
// 遇到数字压栈，遇到符号弹出栈顶的两个数进行操作，结果压栈。
// 注意弹出的两个数运算的顺序 
class Solution {
public:
    void getPar(int& par1, int& par2, stack<int>& s)
    {
        par1 = s.top();
        s.pop();
        par2 = s.top();
        s.pop();
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int par1 = 0,par2 = 0;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i]=="+")
            {
                getPar(par1, par2,s);
                s.push(par2+par1);
            }
            else if (tokens[i]=="-")
            {
                getPar(par1, par2, s);
                s.push(par2-par1);
            }
            else if (tokens[i]=="*")
            {
                getPar(par1, par2, s);
                s.push(par2*par1);
            }
            else if (tokens[i]=="/")
            {
                getPar(par1, par2, s);
                s.push(par2/par1);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
