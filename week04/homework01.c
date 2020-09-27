#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	char arr[101];
	printf("문자를 입력하세요(100자 이내).");
	scanf("%s", arr);
	printf("%s", arr);

	return 0;
}
