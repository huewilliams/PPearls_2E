#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void banner(char *alphabet) {
	int i,j;
	int action = 0;
	int line;
	int count;
	char outputs[100] = "";
	
	for(i=0; i<strlen(alphabet); i++) {
		char inputs[5]="", * count, simbol;
		
		while(alphabet[i]!=' ' && alphabet[i]!='|' && alphabet[i]!='\0') {
			append(inputs, alphabet[i]);
			simbol = alphabet[i];
			if(alphabet[i] == 'b') simbol = ' ';
			i++;
		}
		
		if(action == 0)
			line = atoi(inputs);	
		else if(action % 2 == 1) {
			count = atoi(inputs);		
		} else {
			int k;
			for(k=0; k<count; k++) {
				append(outputs, simbol);
			}
		}
		
		action++;
		
		if(alphabet[i] == '|') {
			int l;
			for(l=0; l<line; l++) {
				printf("%s\n", outputs);
			}
			action = 0;
			outputs[0] = '\0';
		}
	}
}

void append(char *s, char c) {
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}

int main() {
	char I[100] = "2 10 X|8 4 b 2 X|2 10 X|";
	printf("> alphabet 'I' command : %s\n", I);
	banner(I);
}
