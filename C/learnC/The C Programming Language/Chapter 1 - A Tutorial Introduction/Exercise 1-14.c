///*
//	Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
//	in its input.
//*/
//
//#include <stdio.h>
//
//main()
//{
//	int c;
//	int nDigit[10] = { 0 };
//	int maxRow = 0;
//
//	while ((c = getchar()) != EOF)
//		if (c >= '0' && c <= '9')
//			++nDigit[c - '0'];
//
//	for (int i = 0; i < 10; i++)
//		if (nDigit[i] > maxRow)
//			maxRow = nDigit[i];
//
//	for (int i = maxRow; i > 0; i--)
//	{
//		for (int j = 0; j < 10; j++)
//			if (nDigit[j] < i)
//				printf("	");
//			else
//				printf("*	");
//		printf("\n");
//	}
//	printf("1	2	3	4	5	6	7	8	9	0\n");
//	printf("__________________________________________________________________________\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d	", nDigit[i]);
//
//}