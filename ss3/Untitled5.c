#include <stdio.h>
#include <string.h>

int check(char str[], int start, int end) {
    if (start >= end) {
        return 1; 
    }

    if (str[start] != str[end]) {
        return 0;
    }

    return check(str, start + 1, end - 1);
}

int main() {
    char str[1000];

    printf("Nhap vao 1 chuoi: ");
    scanf("%[^\n]", str); 

    printf("Chuoi da nhap: %s\n", str);

    if (check(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

