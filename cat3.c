#include "stdio.h"
#include "stdlib.h"

int main(void) {
	
    char x[10];
    printf("Name a pet: \n");
    gets(x);
    printf("%s could be CAT", x);
    int i = 0;
    
    while (x[i] != 0){
    	printf("\n%d was the ascii value of character %d\n", (int) x[i], i);
    	i++;
    }

    return 0;
}
