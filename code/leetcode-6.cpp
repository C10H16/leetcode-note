//�򵥴ֱ��ķ���
//����һ��vector,���ΰ��ַ��ŵ���Ӧ��λ������� 
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows,"");
        int i = 0,j = 0, k = 0;
        string re = "";
        while (i < s.size())
        {
            for (j = 0; j < numRows; ++j)
            {
                if (i >= s.size())
                    break;
                temp[j] += s[i];
                ++i;
                
            }
            for (k = numRows-2; k > 0; --k)
            {
                if (i >= s.size())
                    break;
                temp[k] += s[i];
                ++i;
            }
        }
        for (i = 0; i < numRows; ++i)
        {
            re += temp[i];
        }
        return re;
    }
};

// ��һ�ַ���
// ��ԭ�ַ������ҵ���Ӧλ�õ��ַ���˳��ŵ��µ��ַ�������
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
            return s;
        int n = 2*numRows - 2;
        int k = 0;
        string re = "";
        for (int i = 0; i < numRows; ++i)
        {
            k = 0;
            if (i==0||i==numRows-1)
            {
                while(k*n+i<s.size())
                {
                    re += s[k*n+i];
                    ++k;
                }
            }
            else
            {
                while(k*n+i<s.size())
                {
                    re += s[k*n+i];
                    if ((k+1)*n-i<s.size())
                        re += s[(k+1)*n-i];
                    ++k;
                }
                
            }
        }
        return re;
    }
}; 
