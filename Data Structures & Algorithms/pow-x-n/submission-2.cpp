class Solution {
public:
    
    double solve(double x, int n) {
        if(n == 0) return 1;

        if(n > 0 && n % 2 == 0) {
            return solve(x*x, n/2);
        }
        else if(n > 0) return solve(x*x, n/2) * x;
    }
    double myPow(double x, int n) {
        long long N = n;

        if(n < 0) {
            x = 1/x;
            N = -N;
        }

        return solve(x, N);
    }
};
