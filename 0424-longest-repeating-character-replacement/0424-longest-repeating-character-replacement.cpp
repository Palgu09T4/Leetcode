class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int left=0,right=0,maxfreq=0,res=0;
        while(right<s.size())
        {
            hash[s[right]-'A']++;
            maxfreq=max(maxfreq,hash[s[right]-'A']);
            while((right-left+1)-maxfreq>k)
            {
                hash[s[left]-'A']--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
     return res;
    }
};