#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
	return *(int*)a - *(int*)b; 
}

// 전역변수는 초기값을 지정해주지 않으면 자동으로 0으로 초기화된다. 
// 지역변수로 배열을 지정할 경우 쓰레기 값으로 채워져 컴파일러에 따라 오류가 발생하기도 한다. 
int arr[10000000];

int main() {
	int i, n=0;
	
	// ctrl+z로 EOF 발생 
	while(scanf("%d", &arr[n]) != EOF)
		n++;
	
	qsort(arr, n, sizeof(int), compare);
	
	for(i=0; i<n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
