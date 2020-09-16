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

// unix time(1970.1.1) 설정 
const int UNIX_YEAR = 1970, UNIX_MONTH = 1, UNIX_DAY = 1;
const enum DayOfWeek UNIX_WEEK = Thursday;

// 1.주어진 두 날짜 사이에 며칠이 포함되었는지를 계산하는 함수  
int calculateDateDifference(int firstYear, int firstMonth, int firstDay, int secondYear, int secondMonth, int secondDay) {
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
			}
			else {
				result += datesOfYear(i);
			}
		}
	}
	
	return result;
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

// 2. 주어진 날짜가 무슨 요일인지를 리턴하는 함수 
int calculateDayOfWeek(int year, int month, int day) {
	int dates = calculateDateDifference(UNIX_YEAR, UNIX_MONTH, UNIX_DAY, year, month, day);
	dates %= 7;
	int i;
	int result = (int)UNIX_WEEK;
	for(i=0; i<dates; i++) 
	{
		result ++;
		if(result > 6) result-=7;
	}
	return result;
}

int main() {
	char option;
	printf(" > option 1 : 두 날짜 사이의 일 수 계산\n");
	printf(" > option 2 : 해당 날짜의 요일 계산\n");
	printf(" > select option. (1 or 2 or 3) : ");
	scanf("%c", &option);

	int result;	
	switch(option) 
	{
		case '1':
			printf(" > option 1 : 두 날짜 사이의 일 수 계산\n");
			
			int firstYear, firstMonth, firstDay;
			int secondYear, secondMonth, secondDay;
		
			printf(" > 첫 번째 날짜를 입력하세요. (형식 : 연도 월 일)\n");
			scanf("%d %d %d", &firstYear, &firstMonth, &firstDay);
			printf(" > 두 번째 날짜를 입력하세요. (형식 : 연도 월 일)\n");
			scanf("%d %d %d", &secondYear, &secondMonth, &secondDay);
			
			result = calculateDateDifference(firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay);
			printf("> %d.%d.%d와 %d.%d.%d는 %d일 차이납니다.", firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay, result);
			break;	
			
		case '2':
			printf(" > option 2 : 해당 날짜의 요일 계산\n");
			
			int year, month, day;
			printf(" > 요일이 알고 싶은 날짜를 입력하세요. (형식 : 연도 월 일)\n");
			scanf("%d %d %d", &year, &month, &day);
			
			result = calculateDayOfWeek(year, month, day);
			
			char * week;
			switch(result)
			{
				case 0:
					week = "일";
					break;
				case 1:
					week = "월";
					break;
				case 2:
					week = "화";
					break;
				case 3:
					week = "수";
					break;
				case 4:
					week = "목";
					break;
				case 5:
					week = "금";
					break;
				case 6:
					week = "토";
					break;
			}
			
			printf("해당 날짜는 %s요일 입니다.", week);
			break;
	}
}
