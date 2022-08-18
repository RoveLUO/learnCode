///*
//	Exercise 1-3. Modify the temperature conversion program to print a heading above the table. 
//*/
//#include <stdio.h>
//
//main() 
//{
//	int fahr;
//	float celsius;
//	int lower, upper, step;
//	lower = 0;
//	upper = 300;
//	step = 20;
//	fahr = lower;
//	printf("Fahrenheit Temperatures -> Centigrade\n");
//	while (fahr <= upper)
//	{
//		celsius = 5 * (fahr - 32) / 9;
//		printf("%3d\t%6.1f\n", fahr, celsius);
//		fahr += step;
//	}
//}