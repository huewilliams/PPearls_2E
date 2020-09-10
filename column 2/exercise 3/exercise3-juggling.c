#include<stdio.h>
#include<stdlib.h>

// ���۸� �˰���, �迭�� ũ�Ⱑ rotate Ƚ���� ����� �Ǿ�� ���� �����ϴ�. 
void rotate(int* arr, int size, int count) {
	count %= size;
	int i, j, temp;
	
	if(size%count==0) {
		for(i=0; i<count; i++) {
			temp = arr[i];
			for(j=i; j+count<size; j+=count) {
				arr[j] = arr[j+count];
			}
			printf("%d:%d\n", j,temp);
			arr[j] = temp;
		}	
	} else {
		printf("> Error: size have to multiple of count!\n");
	}
	
	
}

void main() {
	int size, count, i;
	printf("> input array size\n");
	scanf("%d", &size);
	int * arr = malloc(sizeof(int) * size);
	
	printf("> input array elements list\n");
	for(i=0; i<size; i++) {
		arr[i] = i;
		printf("%d\t", arr[i]);
	}
	
	printf("\n> input rotate count\n");
	scanf("%d", &count);
	rotate(arr, size, count);
	
	printf("> rotate result\n");
	printf("\n");
	for(i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}
}
