class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0},cnt=0,
        minlen=INT_MAX;
        int l=0,r=0,small=-1,m=t.size(),n=s.size();
        for(int i=0;i<m;i++)
        {
            hash[t[i]]++;
        }
        while(r<n)
        {
            if(hash[s[r]]>0)cnt=cnt+1;
            hash[s[r]]--;
            while(cnt==m)
            {
                int len=r-l+1;
                if(len<minlen)
                {
                minlen=len;
                small=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt=cnt-1;
                l++;
            }
            r++;
        }
        return small==-1?"":s.substr(small,minlen);
    }
};