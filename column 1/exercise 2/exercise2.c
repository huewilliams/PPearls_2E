#include <stdio.h>
#include <stdlib.h>

// 1 WORD란 CPU가 한 번에 처리하는 데이터 단위다. 32 bit processor에서는 32bit가 1word가 된다. 
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 100

int a[1 + N/BITSPERWORD];

// a[i>>SHIFT] : SHIFT의 값이 5 이므로 2^5=32, 따라서 i>>SHIFT 값은 i / 32의 몫이 된다.
// MASK의 값이 31이므로 (i & MASK) 의 범위가 0~31로 제한된다.
  
// int set(int i) : i의 값 만큼 1을 SHIFT한 비트를 대입한다.
// a[i>>SHIFT]의 비트 값을 반환한다.  
int set(int i) { return a[i>>SHIFT] |= (1<<(i & MASK)); }

// int clr(int i) : i의 값 만큼 1을 SHIFT한 비트를 NOT 연산 한후 AND 한다. 
// 해당 비트가 1이었을 경우 1을 부정한 0과 AND 연산하므로 해당 비트는 0이 된다. 
int clr(int i) { return a[i>>SHIFT] &= ~(1<<(i & MASK));}

// int test(int i) : i의 값 만큼 1을 SHIFT한 비트와 배열의 해당 인덱스에 저장된 비트를 AND함.
// 배열에 i 값이 저장되어있을 경우, i의 값만큼 1을 SHIFT한 비트를 반환함. 
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
