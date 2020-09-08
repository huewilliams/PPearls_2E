#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
	return *(int*)a - *(int*)b; 
}

// ���������� �ʱⰪ�� ���������� ������ �ڵ����� 0���� �ʱ�ȭ�ȴ�. 
// ���������� �迭�� ������ ��� ������ ������ ä���� �����Ϸ��� ���� ������ �߻��ϱ⵵ �Ѵ�. 
int arr[10000000];

int main() {
	int i, n=0;
	
	// ctrl+z�� EOF �߻� 
	while(scanf("%d", &arr[n]) != EOF)
		n++;
	
	qsort(arr, n, sizeof(int), compare);
	
	for(i=0; i<n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
