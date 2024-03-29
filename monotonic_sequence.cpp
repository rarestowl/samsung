#include <iostream> 
#include <math.h> 
#define SMALL_N 1000000 
#define LARGE_N  1000000000000000 
using namespace std; 
  
// Function to return the value of f(n) for given values of a, b, c, n 
long long func(long long a, long long b, long long c, long long n) 
{ 
    long long res = a * n; 
    long long logVlaue = floor(log2(n)); 
    res += b * n * logVlaue; 
    res += c * (n * n * n); 
    return res; 
} 
  
long long getPositionInSeries(long long a, long long b,  
                             long long c, long long k) 
{ 
    long long start = 1, end = SMALL_N; 
  
    // if c is 0, then value of n can be in order of 10^15. 
    // if c!=0, then n^3 value has to be in order of 10^18 
    // so maximum value of n can be 10^6. 
    if (c == 0) { 
        end = LARGE_N; 
    } 
    long long ans = 0; 
   // for efficient searching, use binary search. 
    while (start <= end) { 
        long long mid = (start + end) / 2; 
        long long val = func(a, b, c, mid); 
        if (val == k) { 
            ans = mid; 
            break; 
        } 
        else if (val > k) { 
            end = mid - 1; 
        } 
        else { 
            start = mid + 1; 
        } 
    } 
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    long long a = 2, b = 1, c = 1; 
    long long k = 12168587437017; 
  
    cout << getPositionInSeries(a, b, c, k); 
  
    return 0; 
} 