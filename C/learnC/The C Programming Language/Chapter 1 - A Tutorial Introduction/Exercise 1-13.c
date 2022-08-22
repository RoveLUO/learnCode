///*
//	Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
//	easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
//*/
//
//#include <stdio.h>
//
//main()
//{
//	int c;
//	int count = 0;
//	int num[11];
//	for (int i = 1; i <= 10; i++)
//		num[i] = 0;
//
//	while ((c = getchar()) != EOF)
//	{
//		if (c == ' ' || c == '\n' || c == '\t')
//		{
//			++num[count];
//			count = 0;
//		}
//		else if (c >= 'A' && c <= 'z')
//			++count;
//	}
//	for (int i = 1; i <= 10; i++)
//	{
//		if (num[i] != 0)
//		{
//			printf("%d ", i);
//			for (int j = 0; j < num[i]; j++)
//				printf("*");
//			printf(" %d\n", num[i]);
//		}
//
//	}
//}