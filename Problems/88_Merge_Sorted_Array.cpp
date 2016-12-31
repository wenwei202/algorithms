class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_idx=m-1,n_idx=n-1;
        int pos = m+n-1;
        while( (m_idx>=0) && (n_idx>=0) ){
            if(nums1[m_idx]>nums2[n_idx]){
                nums1[pos] = nums1[m_idx];
                m_idx--;
            }else{
                nums1[pos] = nums2[n_idx];
                n_idx--;
            }
            pos--;
        }
        while(n_idx>=0){
            nums1[pos] = nums2[n_idx];
            pos--;
            n_idx--;
        }
    }
};