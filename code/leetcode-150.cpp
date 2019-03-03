// 150 �沨�����ʽ��ֵ 
// ��������ѹջ���������ŵ���ջ�������������в��������ѹջ��
// ע�ⵯ���������������˳�� 
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
