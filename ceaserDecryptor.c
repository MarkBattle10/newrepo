#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int Rot13(int num);

int main(){
	FILE *crypticFile;
	FILE *uncodedFile;
	char buff[255];
	char outBuff[255];
	int i;
	char charHolder1[2];
	char charHolder2[2];
	char charHolder3[2];
	int numHolder;
	
	charHolder2[0] = '\0';
	charHolder2[1] = '\0';
	charHolder1[0] = '\0';
	charHolder1[1] = '\0';
	charHolder3[0] = '\0';
	charHolder3[1] = '\0';

	crypticFile = fopen("/root/newrepo/input.txt", "r");
	uncodedFile = fopen("/root/newrepo/uncoded.txt", "w+");
	fgets(buff, 255, (FILE*)crypticFile);
	
	for(i=0;i<=strlen(buff);i++){
		if((buff[i] != ' ')){
			if(buff[i] != '-'){
				if(buff[i+1]!='-'){
					sprintf(charHolder2,"%c",buff[i]);
				}
				else if(buff[i+1]=='-'){
					sprintf(charHolder1,"%c",buff[i]);
					strcat(charHolder2, charHolder1);
					numHolder = atoi(charHolder2);
					numHolder = numHolder+64;
					numHolder = Rot13(numHolder);
					fputc(numHolder, uncodedFile);
					//printf("%c", numHolder);
				}
				
				if(buff[i+1]!=' '){
					sprintf(charHolder3,"%c",buff[i]);
				}
				else if(buff[i+1] == ' '){
					sprintf(charHolder1,"%c",buff[i]);
					strcat(charHolder3, charHolder1);
					numHolder = atoi(charHolder3);
					numHolder = numHolder+64;
					numHolder = Rot13(numHolder);
					fputc(numHolder, uncodedFile);
					//printf("%c", numHolder);
				}
				if(i == strlen(buff)){
					sprintf(charHolder3, "%c",buff[i-2]);
					numHolder = atoi(charHolder3);
					numHolder = numHolder+64;
					numHolder = Rot13(numHolder);
					fputc(numHolder, uncodedFile);
					//printf("%c", numHolder);
				}
			}
			else{
				charHolder2[0] = '\0';
				charHolder2[1] = '\0';
				charHolder1[0] = '\0';
				charHolder1[1] = '\0';
				charHolder3[0] = '\0';
				charHolder3[1] = '\0';
			}
		}
		else{
			fputc(32, uncodedFile);
			//printf(" ");
		}
	}
	
	fclose(crypticFile);
	fclose(uncodedFile);
	
	return 0;
}

int Rot13(int num){
	int tmp;
	if(num<=65+12){
		num = num+13;
	}
	else{
		tmp = 90-num;
		num = 64+(13-tmp);
	}

	return num;
}


