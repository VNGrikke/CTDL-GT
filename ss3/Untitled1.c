#include<stdio.h>

int giaiThua(int n){
	if(n==0){
		return 1;
	}
	
	return n*giaiThua(n-1);
}

int main(){

	int n;
	
	printf("nhap so n: ");
	scanf("%d",&n);
	
	if(n<0){
		printf("n khong dc nho hon 0");
	}
	
	int result = giaiThua(n);
	
	printf("Ket qua: %d", result);
	
	
return 0;
}

