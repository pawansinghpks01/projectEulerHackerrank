#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long sum=0;
        long long prev = 0, curr = 1, next = 1 ;  
    	while(next<n)
        {
        	next=prev+curr;
			prev=curr;
			curr=next;
			if(next%2==0 && next<=n)
				sum+=next;
		}
        cout<<sum<<endl;
    }
    return 0;
}
