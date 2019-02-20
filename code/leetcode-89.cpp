// �Լ��Ĵ���
/*
����n=2ʱ��������Ϊ
00
01
10
11
n=3ʱ��������Ϊ
000
001
010
011
------ 
111
110
101
100 
����n=2�Ļ����ϣ���n=2���ĸ��������������У�����2��n�η���ӣ������µ�4��������
n=4ʱ�������ظ�����Ĳ��������µĸ����롭�� 
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = (int)pow(2,n);
        vector<int> re(size);
        if (n==0)
            return re;
        int i = 0,j = 0,k = 0;
        for (int i = 0; i < n; i++)
        {
            for(j = (int)pow(2,i)-1, k = j+1; j >= 0 ; j--,k++)
            {
                    re[k] = re[j] + (int)pow(2,i);
            }
        }
        return re;
    }
};

// һ�ָ��򵥵ķ��� 
// G(i) = i^(i/2) 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0; i<pow(2,n); ++i)
        {
            res.push_back((i>>1)^i);
        }
        return res;
        
    }
};
