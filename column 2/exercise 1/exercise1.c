#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDMAX 100

int index = 0;

int charcomp(char * a, char * b) {
	return *a - *b;
}

// �� �ܾ� �տ� ǥ��(��ġ� ���� ǥ��, �ܾ� ���� ���� ����) �߰� 
void sign (char *word, char *signword, char** wordList) {
	strcpy(signword, word);
	qsort(signword, strlen(signword), sizeof(char), charcomp);
	strcat(signword, " ");
	strcat(signword, word);
	
	char* tmp = (char*)malloc(sizeof(char) * strlen(signword));
	strcpy(tmp, signword);
	wordList[index] = tmp;
}

// ���ڿ� ����Ʈ ���� ���ķ� ���� 
void strbubblesort(char** wordList) {
	char * temp_str;
	int i,j;
	for(i=0; i<index; i++) {
		for(j=0; j<index-i-1; j++) {
			if(strcmp(wordList[j], wordList[j+1]) > 0) {
				temp_str = wordList[j];
				wordList[j] = wordList[j+1];
				wordList[j+1] = temp_str;
			}
		}
	}
}

// ���� ��ġ����� �� �ٿ� ��� 
void squash(char** wordList) {
	int i;
	char signTemp[WORDMAX]; 
	char tempWord[WORDMAX]; 
	char * signWord;
	char * word;
	
	strcpy(signTemp, wordList[0]);
	signWord = strtok(signTemp, " ");
	
	for(i=0; i<index; i++) {
		strcpy(tempWord, wordList[i]);
		word = strtok(tempWord, " ");
		if(strcmp(signWord, word) == 0) {
			word = strtok(NULL, " ");
			printf("%s\t", word);
		} else {
			strcpy(signTemp, wordList[i]);
			signWord = strtok(signTemp, " ");
			printf("\n%s\t", word);
		}
	}
}

int main() {
	int i;
	char * wordList[WORDMAX];
	char word[WORDMAX], signword[WORDMAX];
	
	printf("> input words\n");
	while (scanf("%s", word) != EOF) {
		sign(word, signword, wordList);
		printf("%s\n", wordList[index++]);
	}
	
	printf("> sign\n");
	for(i=0; i<index; i++) {
		printf("%s\n", wordList[i]);
	}
	
	strbubblesort(wordList);
	
	printf("> string bubble sort\n");
	for(i=0; i<index; i++) {
		printf("%s\n", wordList[i]);
	}
	
	printf("> squash\n");
	squash(wordList);
}
