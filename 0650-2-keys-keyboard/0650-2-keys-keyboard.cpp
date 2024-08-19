class Solution {
public:
    int prime(int n){
        int count=0;
        for(int i=2;i<n;i++){
            if(n%i==0){
                count=i;
            }
        }
        return count;
    }
    unordered_map<int, int> primeFactors(int n) {
    unordered_map<int, int> factors;
    int i = 2;
    
    while (i * i <= n) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
        i++;
    }
    
    if (n > 1) {
        factors[n]++;
    }
    
    return factors;
}

int primeFactorSum(int n) {
    unordered_map<int, int> factors = primeFactors(n);
    int sum = 0;
    
    for (const auto& factor : factors) {
        sum += factor.first * factor.second;
    }
    
    return sum;
}
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        
        if(n==2){
            return 2;
        }
        if(n%2==1){
            int j=prime(n);
            if(j==0){
                return n;
            }
            else{
                return primeFactorSum(n);
            }
        }
        return 2+minSteps(n/2);
    }
};