// ±¨Êý 
class Solution {
public:
    string countAndSay(int n) {
        if (n==1)
            return "1";
        int i = 2,j = 0,count = 0;
        char itoc[]={'1','1','2','3'};
        string a = "11";
        string b = "";
        char c = '1';
        for(i; i < n; ++i)
        {
            count = 1;
            for(j = 1; j < a.size(); ++j)
            {
                if (a[j] == c)
                {
                    ++count;
                }
                else
                {
                    b  = b + itoc[count] + c;
                    c = a[j];
                    count = 1;
                }
            }
            b = b + itoc[count] + c;

            a = b;
            b = "";
            c = a[0];
        }
        return a;
    }
};
