/*
Question Source: "HackerRank (Project Euler)"
Problem URL: "https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem"
Solution by: "https://github.com/pawansinghpks01"
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++){
        
        /*Use long long in C++ as int can't store some of the input numbers*/
        long long number;
        
        cin >> number;
        
        //decreasing number by 1 as it's mentioned 'find the sum ... below "N"'
        number--;
        
        /*a, b and c are the number of terms we will have if we consider 3APs as follows:
        3, 6, 9, 12, .... up to "number" --- 'a' is the number of terms this series will have 
        5, 10, 15, 20, .... up to "number" --- 'b' is the number of terms this series will have
        15, 30, 45, 60, .... up to "number" --- 'c' is the number of terms this series will have
        */
        
        long long a = number/3, b = number/5, c = number/15;
        
        /*To solve this question, we basically need to find the sum - of all the natural numbers (below 'n' ofcourse)
            Add -> sum of all the multiples of 3
            Add -> sum of all the multiples of 5
            but in this process we added the common multiple of 3 and 5 twice, so subtract that from the sum
            Sub -> sum of all the multiples of 15
        */
        
        long long sum3 = (((a*(a+1))/2)*3);
        long long sum5 = (((b*(b+1))/2)*5);
        long long sum15 = (((c*(c+1))/2)*15);
        long long ans = sum3 + sum5 - sum15;
        
        cout << ans << endl;
    }
    return 0;
}
