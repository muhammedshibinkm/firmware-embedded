/* Identity Property: 
𝐴⊕0=𝐴
A⊕0=A. XORing a number with zero leaves the number unchanged.
Commutative and Associative Properties: The order in which you XOR the numbers doesn't change the result. That is, 
𝐴⊕𝐵⊕𝐶=𝐶⊕𝐵⊕𝐴
A⊕B⊕C=C⊕B⊕A and so on.
Self-Inversion Property: 
𝐴⊕𝐴=0
A⊕A=0. XORing a number with itself cancels it out to zero.
*/
#include <stdio.h>

int findSingle(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 10, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element that does not repeat is: %d\n", findSingle(arr, n));
    return 0;
}
