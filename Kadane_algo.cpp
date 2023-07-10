/* Question Link:
https://leetcode.com/problems/maximum-subarray/
https://bit.ly/3HZltTa */

//Used Kadanes Algorithm to solve this one
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=INT_MIN;
        int me=0;
        int s=nums.size();
        for(int i=0;i<s;i++)
        {
            me=me+nums[i];
            if(ms<me)
            {
                ms=me;
            }
            if(me<0)
            {
                me=0;
            }
        }
        return ms;
    }
};
