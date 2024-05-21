/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.*/
/*try to use better sorting alogorithm, here i used merge sort algorithm sorting part, 
  for median, if the merged array size is even , take average of middle two elements, 
  if the size is odd, take middle element */

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int final_size = size1+size2;
        vector<int>final(final_size);
        double sum = 0;
        int i = 0, j=0,k=0;
        while(i<size1 && j<size2)
        {
            if(nums1[i] < nums2[j]) {
                final[k++] = nums1[i++];
            } else {
                final[k++] = nums2[j++];
            }
        }
        while(i < size1) 
        {
            final[k++] = nums1[i++]; 
        }
        while(j < size2)
        {
            final[k++] = nums2[j++];
        }
        if(final_size%2 == 0)
        {
            sum = (final[final_size/2] + final[(final_size - 1)/2]) / (double)2;
        }
        else {
            sum = final[final_size/2];
        }

        return sum;
        
    }
};
