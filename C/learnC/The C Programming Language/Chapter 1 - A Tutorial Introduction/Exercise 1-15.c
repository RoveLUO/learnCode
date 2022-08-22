///*
//	Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
//	for conversion.
//*/
//
//#include <stdio.h>
//
//double temperatureConversion(int lower, int upper, int step);
//
//main()
//{
//	temperatureConversion(0, 300, 20);
//}
//
//double temperatureConversion(int lower, int upper, int step)
//{
//	int fahr = lower;
//	double celsius;
//	while (fahr <= upper) {
//		celsius = 5 * (fahr - 32) / 9;
//		printf("%d\t%3.0f\n", fahr, celsius);
//		fahr = fahr + step;
//	}
//}
