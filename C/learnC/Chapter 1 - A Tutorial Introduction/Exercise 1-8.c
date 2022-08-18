///*
//	Exercise 1-8. Write a program to count blanks, tabs, and newlines.
//*/
//
//#include <stdio.h>
//
//int main()
//{
//	int c, spaceCount, tableCount, newlineCount;
//	spaceCount = 0;
//	tableCount = 0;
//	newlineCount = 0;
//	while ((c = getchar()) != EOF)
//		if (c == ' ')
//			++spaceCount;
//		else if (c == '\t')
//			++tableCount;
//		else if (c == '\n')
//			++newlineCount;
//	printf("space count = %d\n", spaceCount);
//	printf("table count = %d\n", tableCount);
//	printf("new line count = %d\n", newlineCount);
//}