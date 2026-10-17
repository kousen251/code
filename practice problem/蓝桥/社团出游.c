#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int N,K;
	long long C,B;
	
	scanf("%d %d %lld %lld", &N, &K, &C, &B);
	
	int amount[100005];
	int i;
	for(i = 0;i < N ; i++){
		scanf("%d", &amount[i]);
	}
	
	long long sum = 0;
	int answer;
	
	for(i = 0; i < N; i++) {
		int people = i + 1;
		long long cars;
		long long total;
		
		sum += amount[i];
		
		cars = (people + K - 1) / K;
		total = sum + cars * C;
		if(total <= B){
			answer = people;
		}
	}
	printf("%d\n", answer);
	
	return 0;
	}