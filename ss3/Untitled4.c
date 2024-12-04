#include<stdio.h>
#include <string.h>

void reverse(char str[], int start, int end){
	if (start >= end) {
        return; 
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1);
}

int main(){

	char str[1000];

	printf("nhap vao 1 chuoi: ");
    scanf("%[^\n]", str);
    
    printf("Chuoi da nhap: %s \n", str);
    
    reverse(str, 0, strlen(str)-1);
    
    printf("Chuoi dao nguoc: %s", str);

return 0;
}

