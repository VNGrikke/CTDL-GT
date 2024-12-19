#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int point;
};

int main() {
    int n, found = 0;
    char searchName[50];
    
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    
    struct Student students[n];
    printf("Nhap ten va diem cua sinh vien\n");

    for (int i = 0; i < n; i++) {
        scanf("%s %d", &students[i].name, &students[i].point);
    }
    
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Diem cua %s là: %d\n", students[i].name, students[i].point);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay\n");
    }
    
    return 0;
}

