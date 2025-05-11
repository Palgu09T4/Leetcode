class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int left=0,right=0,minlen=INT_MAX,start=-1,cnt=0;
        for(char c:t)
        {
            hash[c]++;
        }
        while(right<s.size())
        {
            if(hash[s[right]]>0)
            {
                cnt++;
            }
            hash[s[right]]--;
            while(cnt==t.size())
            {
                if((right-left+1)<minlen)
                {
                    minlen=right-left+1;
                    start=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0)
                {
                    cnt--;
                }
                left++;
            }
            right++;
        }

      return start==-1?"":s.substr(start,minlen);
    }
};