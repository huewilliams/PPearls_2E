#include <stdio.h>
#include <stdlib.h>

// �迭 ȸ�� �˰��� (���� ����) 
void rotate(int* arr, int count, int size) {
	int i;
	
	// �迭�� ���̸�ŭ ȸ���ϸ� ���� �迭�� �����Ƿ� ���ʿ��� ������ ����. 
	count %= size;
	
	reverse(arr, 0, count, size);

	reverse(arr, count, size, size);

	reverse(arr, 0, size, size);
}

// start ���� end-1 ������ ��Ҹ� reverse. 
void reverse(int* arr, int start, int end, int size) {
	int *newArr = malloc(sizeof(int) * size);
	int i, j;
	
	for(i=0; i<start; i++)
		newArr[i] = arr[i];
	
	for(i=start, j=0; i<end; i++, j++)
		newArr[i] = arr[end-1-j];
	
	for(i=end; i<size; i++) 
		newArr[i] = arr[i];
	
	for(i=0; i<size; i++) 
		arr[i] = newArr[i];
}

void main() {
	int size, i;
	
	printf("> input arrary length\n");
	scanf("%d", &size);
	
	int *arr = malloc(sizeof(int) * size);
	
	printf("> arrary elements\n");
	for(i=0; i<size; i++) {
		arr[i] = i;
		printf("%d\t", i);
	}	
	
	printf("\n> input rotate count\n");
	int count;
	scanf("%d", &count);
	rotate(arr, count, size);
	
	printf("> rotate result\n");
	for(i=0; i<size; i++)
		printf("%d\t", arr[i]);
	
	free(arr);
}
