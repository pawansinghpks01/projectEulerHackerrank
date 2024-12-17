#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void primes(int N, bool* isprime) {
    int i, j;
    /* first, set odd numbers to prime, evens to not-prime */
    for (i = 0; i < N; ++i) isprime[i] = i % 2 == 1;
    
    /* special cases for i<3 */
    isprime[0] = isprime[1] = false;

    /* Compute square root via newton's algorithm 
     * (this can be replaced by 'i * i <= N' in the foor loop)
     */
    int sqrtN = (N >> 10) + 1024;
    for (i = 0; i < 32; ++i) sqrtN = (N / sqrtN + sqrtN) / 2;

    /* iterate through all odd numbers */
    isprime[2] = true;
    for (i = 3; i <= sqrtN /* or: i*i <= N */; i += 2) {
        /* check if this odd number is still prime (i.e. if it has not been marked off) */
        if (isprime[i]) {

            /* mark off multiples of the prime */
            j = 2 * i;
            isprime[j] = false;
            for (j += i; j < N; j += 2 * i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    cin >> N;
    
    bool isprime[N];
    primes(N,isprime);
    
    // for (int z=0; z<N; z++)
    //     cout<<z<<" is prime? "<<((isprime[z]==true)?"Yes":"No")<<endl;
    
    int sum=0,flag;
    
    for(int i=11; i<N; i++){
        if(isprime[i]){
            int fp=i,rp=i;
            //cout<<"\ni is: "<<i<<" \n";
            flag=1;
            
            while (fp>0 && fp/10>0){
                int temp=(fp/10);
                //cout<<"temp=(fp/10) = "<<temp<<endl;
                if(isprime[temp]){
                    flag=1;
                    //cout<<" flag 1 -- OK"<<endl;
                }
                else{
                    flag=0;
                    //cout<<" flag 0 -- NOK"<<endl;
                    break;
                }
                fp=fp/10;
            }
            if(flag==0){
                continue;
            }
            int x=10;
            while (rp>0 && rp/x>0){
                int temp = (rp%x);
                //cout<<"temp = (rp%x) = "<<temp<<endl;
                if(isprime[temp]){
                    flag=1;
                }
                else{
                    flag=0;
                    break;
                }
                x=x*10;
            }
            
            if(flag==1){
                //cout<<i<<endl;
                sum+=i;
            }
        }
    }
    
    cout<<sum;
    
    return 0;
}
