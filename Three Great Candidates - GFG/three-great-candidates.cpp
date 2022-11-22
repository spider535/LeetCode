//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        // code here
        long long mx1 = INT_MIN,mx2 = INT_MIN,mx3 = INT_MIN,mn1 = INT_MAX,mn2 = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > mx3){
                mx3 = arr[i];
                if(mx3 > mx2)
                    swap(mx3,mx2);
                if(mx2 > mx1)
                    swap(mx2,mx1);
            }
            if(mn2 > arr[i]){
                mn2 = arr[i];
                if(mn2 < mn1)
                    swap(mn2,mn1);
            }
        }
        return max(mn1*mn2*mx1,mx1*mx2*mx3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends