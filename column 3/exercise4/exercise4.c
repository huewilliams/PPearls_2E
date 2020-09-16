#include <stdio.h>
#include <stdlib.h>

enum DayOfWeek {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

// 주어진 두 날짜 사이에 며칠이 포함되었는지를 계산하는 함수  
void calculateDateDifference() {
	int firstYear, firstMonth, firstDay;
	int secondYear, secondMonth, secondDay;
	
	printf(" > 첫 번째 날짜를 입력하세요. 형식 : 연도 월 일\n");
	scanf("%d %d %d", &firstYear, &firstMonth, &firstDay);
	printf(" > 두 번째 날짜를 입력하세요. 형식 : 연도 월 일\n");
	scanf("%d %d %d", &secondYear, &secondMonth, &secondDay);
	
	int result = 0;
	int i, temp;
	if(firstYear == secondYear) result = secondDay - firstDay;
	else {
		for(i=firstYear; i<=secondYear; i++) {
			if(i == firstYear) {
				result += (datesOfYear(firstYear) - dateCounts(datesOfYear(firstYear), firstMonth, firstDay));
			}
			else if(i == secondYear) {
				result += dateCounts(datesOfYear(secondYear), secondMonth, secondDay); 
			}else {
				result += datesOfYear(i);
			}
		}
	}
	
	printf("> %d.%d.%d와 %d.%d.%d는 %d일 차이납니다.", firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay, result);
}

// 윤년인지 아닌지 판단하는 함수 
int datesOfYear(int year) {
	int dates;
	if((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 366;
	else
		return 365;
}

// 해당 날짜가 해당 년도 1월 1일 부터 몇 일 경과됬는지 반환하는 함수 
int dateCounts(int dates, int month, int day) {
	int count = 0;
	int monthDates[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// 윤년이면 2월 29일 
	if(dates > 365) monthDates[1]++;
	
	int i;
	for(i=0; i<month; i++) {
		if(i+1 == month) {
			count += day;
		} else {
			count += monthDates[i];
		}
	}
	
	return count;
}

int main() {
	// unix time(1970.1.1) 설정 
	int unixYear = 1970, unixMonth = 1, unixDay = 1;
	enum DayOfWeek unixWeek = Thursday;
	
	char option;
	printf(" > option 1 : 두 날짜 사이의 일 수 계산\n");
	printf(" > select option. (1 or 2 or 3) : ");
	scanf("%c", &option);
	
	switch(option) 
	{
	case '1':
		printf(" > option 1 : 두 날짜 사이의 일 수 계산\n");
		calculateDateDifference();
		break;	
	}
}
