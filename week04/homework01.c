#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	char arr[101];
	printf("문자를 입력하세요(100자 이내).\n");
	scanf("%s", arr);
	printf("입력된 문자는 %s 입니다.", arr);

	return 0;
}
