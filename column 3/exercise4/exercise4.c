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

// �־��� �� ��¥ ���̿� ��ĥ�� ���ԵǾ������� ����ϴ� �Լ�  
void calculateDateDifference() {
	int firstYear, firstMonth, firstDay;
	int secondYear, secondMonth, secondDay;
	
	printf(" > ù ��° ��¥�� �Է��ϼ���. ���� : ���� �� ��\n");
	scanf("%d %d %d", &firstYear, &firstMonth, &firstDay);
	printf(" > �� ��° ��¥�� �Է��ϼ���. ���� : ���� �� ��\n");
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
	
	printf("> %d.%d.%d�� %d.%d.%d�� %d�� ���̳��ϴ�.", firstYear, firstMonth, firstDay, secondYear, secondMonth, secondDay, result);
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

int main() {
	// unix time(1970.1.1) ���� 
	int unixYear = 1970, unixMonth = 1, unixDay = 1;
	enum DayOfWeek unixWeek = Thursday;
	
	char option;
	printf(" > option 1 : �� ��¥ ������ �� �� ���\n");
	printf(" > select option. (1 or 2 or 3) : ");
	scanf("%c", &option);
	
	switch(option) 
	{
	case '1':
		printf(" > option 1 : �� ��¥ ������ �� �� ���\n");
		calculateDateDifference();
		break;	
	}
}
