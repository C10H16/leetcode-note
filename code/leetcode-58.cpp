// 58-最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size()-1;
        if (s[n]==' ')
        {
           
            while (s[n]==' ')
                --n;
        }
        if (s.empty()||n<0)
            return 0;
        for(int i = n; i >=0; --i)
        {
            if (s[i]==' ')
                break;
            count ++;
        }
        return count;
    }
}; 
