#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


//각 수의 초기값의 max를 기억하는 배열
long long int memo[1000000001];

long long int finding(long long int champ[], long long int k, long long int x){
    long long int i;
    for(i = 0; i <= k; i++){
        if(champ[i] == x) return 0;
    }
    return 1;
}

long long int f(long long int n, long long int max) {
    if(n > max){max = n;}
	
	if(memo[n]){
	    if(memo[n] >= max) return memo[n];
    	
    	else if(memo[n] < max) return max;
	}
	
	
	if(n==1) return max;
	
	//짝수일 경우
	if (n % 2 == 0)
		return f(n / 2, max);
	else
		return f(n*3 + 1, max);
}

int main() {
	long long int min=1, max=1000000000;
	//scanf("%d", &max);
	long long int champ[1000000001];
	long long int k=0;
	for (long long int i = min; i <= max; i++) {
   		//우박수의 최댓값를 기억시킨다
		memo[i] = f(i, 0);
		
		if (i*100 < memo[i] && finding(champ, k, memo[i])){
		    printf("%lld %lld\n", i, memo[i]);
		    champ[k] = memo[i]; k++;
		}
		
	}
	
	//printf("%lld %lld", max, f(max,0));
	
	
}

