#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if(N <= 2)return N;
        vector<long int>A(N+1,0);
        vector<long int>B(N+1,0);
        A[1] = 1;
        A[2] = 2;
        B[1] = 0;
        B[2] = 1;
        int mod = 1000000007;
        for(int i=3;i<=N;i++)
        {
            A[i] = (A[i-1]+A[i-2]+ 2*B[i-1])%mod;
            B[i] = (B[i-1] + A[i-2])%mod;
        }

        return A[N];

    }
};

int main() {
    Solution s;
    cout << s.numTilings(4);
    return 0;
}
