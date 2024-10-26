class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
      int  right=0;
      while(left>=0 && right<n)
      {
        if(nums1[left]>nums2[right])
        {
            swap(nums1[left],nums2[right]);
            left--,right++;
        }
        else
        {
        break;
        }
      }
      for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
      sort(nums1.begin(),nums1.end());
     
    }
};