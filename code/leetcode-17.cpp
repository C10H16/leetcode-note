// 17 电话号码的字母组合 
class Solution {
public:       
    map <char, string> table = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    
    void insertToStr(string s,int i, string digits,vector<string>& re)
    {
        if (i >= digits.size())
            {re.push_back(s);return;}
        else
        {
            for(int j = 0; j < table[digits[i]].size(); ++j)
            {
                s[i] = table[digits[i]][j];
                insertToStr(s, i+1, digits,re);
            }
        }

    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        if (digits.size()==0)
            return re;
        string s(digits.size(),' ');
        int i = 0;
        insertToStr(s,i,digits,re);
        return re;
    }
}; 
