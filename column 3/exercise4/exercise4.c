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

// unix time(1970.1.1) ���� 
const int UNIX_YEAR = 1970, UNIX_MONTH = 1, UNIX_DAY = 1;
const enum DayOfWeek UNIX_WEEK = Thursday;

// 1.�־��� �� ��¥ ���̿� ��ĥ�� ���ԵǾ������� ����ϴ� �Լ�  
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

// �������� �ƴ��� �Ǵ��ϴ� �Լ� 
int datesOfYear(int year) {
	int dates;
	if((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 366;
	else
		return 365;
}

// �ش� ��¥�� �ش� �⵵ 1�� 1�� ���� �� �� �������� ��ȯ�ϴ� �Լ� 
int dateCounts(int dates, int month, int day) {
	int count = 0;
	int monthDates[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// �����̸� 2�� 29�� 
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

// 2. �־��� ��¥�� ���� ���������� �����ϴ� �Լ� 
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
	printf(" > option 1 : �� ��¥ ������ �� �� ���\n");
	printf(" > option 2 : �ش� ��¥�� ���� ���\n");
	printf(" > select option. (1 or 2 or 3) : ");
	scanf("%c", &option);

	int result;	
	switch(option) 
	{
		case '1':
			printf(" > option 1 : �� ��¥ ������ �� �� ���\n");
			
			int firstYear, firstMonth, firstDay;
			int secondYear, secondMonth, secondDay;
		
			printf(" > ù ��° ��¥�� �Է��ϼ���. (���� : ���� �� ��)\n");
			scanf("%d %d %d", &firstYear, &firstMonth, &firstDay);
			printf(" > �� ��° ��¥�� �Է��ϼ���. (���� : ���� �� ��)\n");
			scanf("%d %d %d", &secondYear, &secondMonth, &secondDay);
			
			result = calculateDateDifference(firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay);
			printf("> %d.%d.%d�� %d.%d.%d�� %d�� ���̳��ϴ�.", firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay, result);
			break;	
			
		case '2':
			printf(" > option 2 : �ش� ��¥�� ���� ���\n");
			
			int year, month, day;
			printf(" > ������ �˰� ���� ��¥�� �Է��ϼ���. (���� : ���� �� ��)\n");
			scanf("%d %d %d", &year, &month, &day);
			
			result = calculateDayOfWeek(year, month, day);
			
			char * week;
			switch(result)
			{
				case 0:
					week = "��";
					break;
				case 1:
					week = "��";
					break;
				case 2:
					week = "ȭ";
					break;
				case 3:
					week = "��";
					break;
				case 4:
					week = "��";
					break;
				case 5:
					week = "��";
					break;
				case 6:
					week = "��";
					break;
			}
			
			printf("�ش� ��¥�� %s���� �Դϴ�.", week);
			break;
	}
}
