#include <stdio.h>
#include <stdlib.h>

// 1 WORD�� CPU�� �� ���� ó���ϴ� ������ ������. 32 bit processor������ 32bit�� 1word�� �ȴ�. 
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 100

int a[1 + N/BITSPERWORD];

// a[i>>SHIFT] : SHIFT�� ���� 5 �̹Ƿ� 2^5=32, ���� i>>SHIFT ���� i / 32�� ���� �ȴ�.
// MASK�� ���� 31�̹Ƿ� (i & MASK) �� ������ 0~31�� ���ѵȴ�.
  
// int set(int i) : i�� �� ��ŭ 1�� SHIFT�� ��Ʈ�� �����Ѵ�.
// a[i>>SHIFT]�� ��Ʈ ���� ��ȯ�Ѵ�.  
int set(int i) { return a[i>>SHIFT] |= (1<<(i & MASK)); }

// int clr(int i) : i�� �� ��ŭ 1�� SHIFT�� ��Ʈ�� NOT ���� ���� AND �Ѵ�. 
// �ش� ��Ʈ�� 1�̾��� ��� 1�� ������ 0�� AND �����ϹǷ� �ش� ��Ʈ�� 0�� �ȴ�. 
int clr(int i) { return a[i>>SHIFT] &= ~(1<<(i & MASK));}

// int test(int i) : i�� �� ��ŭ 1�� SHIFT�� ��Ʈ�� �迭�� �ش� �ε����� ����� ��Ʈ�� AND��.
// �迭�� i ���� ����Ǿ����� ���, i�� ����ŭ 1�� SHIFT�� ��Ʈ�� ��ȯ��. 
int test(int i) { return a[i>>SHIFT] & (1<<(i & MASK));}

int main() {
	int i = 34;
	int j = 66;
	int k = 5;
	// reuslt : 1, 2, 4 
	printf("i>>shift : %d , i&MASK : %d , 1<<(i&MASK) : %d\n", i>>SHIFT, i&MASK, 1<<(i&MASK));
	// result : 2, 2, 4
	printf("j>>shift : %d , j&MASK : %d , 1<<(j&MASK) : %d\n", j>>SHIFT, j&MASK, 1<<(j&MASK));
	// result : 0, 5, 32
	printf("k>>shift : %d , k&MASK : %d , 1<<(k&MASK) : %d\n", k>>SHIFT, k&MASK, 1<<(k&MASK));
	// 32
	printf("%d\n", set(5));
	// 40
	printf("%d\n", set(3)); 
	// 32
	printf("%d\n", test(5));
	// 8
	printf("%d\n", clr(5));
	// 0
	printf("%d\n", test(5));
	// 8
	printf("%d\n", test(3));
}
