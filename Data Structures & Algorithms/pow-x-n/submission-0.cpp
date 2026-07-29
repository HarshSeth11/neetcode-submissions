class Solution {
public:
    double myPow(double x, int n) {
        double product = x;
        

        if(n > 0) {
            for(int i=1; i<n; i++) {
                product *= x;
            }
        }
        else {
            for(int i=n; i<=0; i++) {
                product /= x;
            }
        }

        return product;
    }
};
