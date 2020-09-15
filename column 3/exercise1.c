#include <stdio.h>
#include <stdlib.h>

// 연습문제 1의 25개의 if 문으로 이루어진 소득세 계산표를 if 문 하나로 구성된 계산 함수로 만들었다. 
float taxCalc(int income) {
	if(income <= 2200)
		return 1;
	else {
		int count = 0;
		int standard = 2700;
		int constant = 0; 
		int addend = 70;
		while(standard < income) {
			count ++;
			standard += 500;
			constant += addend;
			addend += 5;
		}
		
		float ratio = 0.14 + 0.01 * count;
		int coefficient = income + 500 - standard;
		printf("count: %d, standard : %d, coefficient: %d, ratio: %f, constant: %d\n", count, standard, coefficient, ratio, constant); 
		printf("%d + %f * %d\n", constant, ratio, coefficient);
		
		return constant + ratio * coefficient;
	}
}

void main() {
	printf("> input income.\n");
	int input;
	scanf("%d", &input);
	
	printf("> calculate tax : %f\n", taxCalc(input));
}
